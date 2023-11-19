//
// Created by Max Kienast on 17.10.23.
//

#include <netinet/in.h>
#include <sys/select.h>
#include <unistd.h>
#include "TcpServerController.h"
#include "TcpClient.h"
#include "TcpClientServiceManager.h"

unsigned char client_recv_buffer[MAX_CLIENT_BUFFER_SIZE];

TcpClientServiceManager::TcpClientServiceManager(TcpServerController *tcp_ctrlr) {
    this->tcp_ctrlr = tcp_ctrlr;
    this->max_fd = 0;
    FD_ZERO(&this->active_fd_set);
    FD_ZERO(&this->backup_fd_set);
    client_svc_mgr_thread = (pthread_t *)calloc(1, sizeof(pthread_t));
}

TcpClientServiceManager::~TcpClientServiceManager(){
}

void TcpClientServiceManager::StartTcpClientServiceManagerThreadInternal() {
    // Invoke select system call on all clients present in Client DB
    int rev_bytes;
    TcpClient *tcp_client, *next_tcp_client;
    struct sockaddr_in client_addr;
    std::list<TcpClient *>::iterator it;
    socklen_t addr_len = sizeof(client_addr);

    while (true) {
        memcpy(&this->active_fd_set, &this->backup_fd_set, sizeof(fd_set));
        select(this->max_fd + 1, &this->active_fd_set, 0, 0, 0);

        for (it = this->tcp_client_db.begin(); it != this->tcp_client_db.end(); ++it) {
            tcp_client = *it;
            next_tcp_client = *(++it);

            if (FD_ISSET(tcp_client->comm_fd, &this->active_fd_set)) {
                rev_bytes = recvfrom(
                        tcp_client->comm_fd,
                        client_recv_buffer,
                        MAX_CLIENT_BUFFER_SIZE,
                        0,
                        (struct sockaddr *)&client_addr,
                        &addr_len
                );

                if (rev_bytes == 0) {
                    printf("error no - %d\n", errno);
                    sleep(1);
                }

                if (tcp_client->msgd) {
                    tcp_client->msgd->ProcessMsg(tcp_client, client_recv_buffer, rev_bytes);
                }

                if (this->tcp_ctrlr->client_msg_received) {
                    this->tcp_ctrlr->client_msg_received(this->tcp_ctrlr, tcp_client, client_recv_buffer, rev_bytes);
                }
            }
            memset(client_recv_buffer, 0, rev_bytes);
        }
    }
}

void *tcp_client_svc_mgr_thread_fn(void *arg) {
    TcpClientServiceManager *svc_mgr = (TcpClientServiceManager *) arg;
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcancelstate(PTHREAD_CANCEL_DEFERRED, NULL);
    svc_mgr->StartTcpClientServiceManagerThreadInternal();
    return NULL;
}

void TcpClientServiceManager::StartTcpClientServiceManagerThread() {
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(this->client_svc_mgr_thread, &attr, tcp_client_svc_mgr_thread_fn, (void*)this);
    printf("Service started: TcpClientServiceManagerThread\n");
}

void TcpClientServiceManager::ClientFdStartListen(TcpClient *tcpClient) {
    this->StopTcpClientServiceManagerThread();
    printf("Client Service Manager Thread is cancelled.\n");

    this->AddClientToDB(tcpClient);

    this->client_svc_mgr_thread = (pthread_t *)calloc(1, sizeof(pthread_t));
    this->StartTcpClientServiceManagerThread();
}

int TcpClientServiceManager::GetMaxFd() {
    int max_fd_lcl = 0;
    TcpClient *tcp_client;
    std::list<TcpClient *>::iterator it;

    for (it = this->tcp_client_db.begin(); it != this->tcp_client_db.end(); ++it) {
        tcp_client = *it;
        if (tcp_client->comm_fd > max_fd_lcl ) {
            max_fd_lcl = tcp_client->comm_fd;
        }
    }
    return max_fd_lcl;
}

void TcpClientServiceManager::CopyClientFDtoFDSet(fd_set *fdset) {

    TcpClient *tcp_client;
    std::list<TcpClient *>::iterator it;

    for (it = this->tcp_client_db.begin(); it != this->tcp_client_db.end();++it) {
        tcp_client = *it;
        FD_SET(tcp_client->comm_fd, fdset);
    }
}

TcpClient* TcpClientServiceManager::LookUpClientDB(uint32_t ip_addr, uint16_t port_no) {
    TcpClient *tcp_client;
    std::list<TcpClient *>::iterator it;

    for (it = this->tcp_client_db.begin(); it != this->tcp_client_db.end(); ++it) {
        tcp_client = *it;

        if (tcp_client->ip_addr == ip_addr && tcp_client->port_no == port_no)
            return tcp_client;
    }

    return NULL;
}

void TcpClientServiceManager::AddClientToDB(TcpClient *tcp_client){
    this->tcp_client_db.push_back(tcp_client);
}

void TcpClientServiceManager::StopTcpClientServiceManagerThread() {
    pthread_cancel(*this->client_svc_mgr_thread);
    pthread_join(*this->client_svc_mgr_thread, NULL);
    free(this->client_svc_mgr_thread);
    this->client_svc_mgr_thread = NULL;
}
