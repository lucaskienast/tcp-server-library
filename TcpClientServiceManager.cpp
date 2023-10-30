//
// Created by Max Kienast on 17.10.23.
//

#include "TcpServerController.h"
#include "TcpClient.h"
#include "TcpClientServiceManager.h"

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

}

void *tcp_client_svc_mgr_thread_fn(void *arg) {
    TcpClientServiceManager *svc_mgr = (TcpClientServiceManager *) arg;
    svc_mgr->StartTcpClientServiceManagerThreadInternal();
    return NULL;
}

void TcpClientServiceManager::StartTcpClientServiceManagerThread() {
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(this->client_svc_mgr_thread, &attr, tcp_client_svc_mgr_thread_fn, (void*)this);
}

void TcpClientServiceManager::ClientDfStartListen(TcpClient *) {

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
