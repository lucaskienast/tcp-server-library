//
// Created by Max Kienast on 17.10.23.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include "TcpServerController.h"
#include "TcpNewConnectionAcceptor.h"
#include "TcpClient.h"
#include "network_utils.h"

TcpNewConnectionAcceptor::TcpNewConnectionAcceptor(TcpServerController *tcp_ctrlr) {
    this->accept_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (this->accept_fd < 0) {
        printf("Error: Could not create Accept File Descriptor");
        exit(0);
    }

    this->accept_new_conn_thread = (pthread_t *)calloc(1, sizeof (pthread_t));
    this->tcp_ctrlr = tcp_ctrlr;
}

TcpNewConnectionAcceptor::~TcpNewConnectionAcceptor(){
}


void TcpNewConnectionAcceptor::StartTcpNewConnectionAcceptorThreadInternal() {
    int opt = 1;
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(this->tcp_ctrlr->port_no);
    server_addr.sin_addr.s_addr = htonl(this->tcp_ctrlr->ip_addr);

    if (setsockopt(
            this->accept_fd,
            SOL_SOCKET,
            SO_REUSEADDR,
            (char *)&opt,
            sizeof(opt)) < 0){
        printf("setsockopt FAILED\n");
    }

    if (setsockopt(
            this->accept_fd,
            SOL_SOCKET,
            SO_REUSEPORT,
            (char *)&opt,
            sizeof(opt)) < 0){
        printf("setsockopt FAILED\n");
    }

    if (bind(this->accept_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == 1) {
        printf("Error: Acceptor socket bind failed [%s(0x%x), %d], error = %d\n",
               network_convert_ip_n_to_p(this->tcp_ctrlr->ip_addr, 0),
               this->tcp_ctrlr->ip_addr,
               this->tcp_ctrlr->port_no,
               errno);
    }

    if (listen(this->accept_fd, 5) < 0) {
        printf("listen FAILED\n");
    }

    struct sockaddr_in client_addr;
    socklen_t  addr_len = sizeof(client_addr);
    int comm_sock_fd;

    // Create infinite loop
    while (true) {
        // Invoke accept() to accept to new connections
        comm_sock_fd = accept(this->accept_fd, (struct sockaddr *)&client_addr, &addr_len);

        if (comm_sock_fd < 0) {
            printf("Error in accepting new connection\n");
            continue;
        }

        TcpClient *tcp_client = new TcpClient(
                client_addr.sin_addr.s_addr,
                client_addr.sin_port
                );

        tcp_client->tcp_ctrlr = this->tcp_ctrlr;
        tcp_client->comm_fd = comm_sock_fd;

        if (this->tcp_ctrlr->client_connected) {
            this->tcp_ctrlr->client_connected(this->tcp_ctrlr, tcp_client);
        }

        // Tell TCP controller of new connection to further process the client
        this->tcp_ctrlr->ProcessNewClient(tcp_client);

        printf("Connection accepted from client [%s, %d]",
               network_convert_ip_n_to_p(htonl(client_addr.sin_addr.s_addr), 0),
               htons(client_addr.sin_port));
    }
}

static void* tcp_listen_for_new_connections(void *arg) {
    TcpNewConnectionAcceptor *tcpNewConnectionAcceptor = (TcpNewConnectionAcceptor *) arg;
    tcpNewConnectionAcceptor->StartTcpNewConnectionAcceptorThreadInternal();
    return nullptr;
}

void TcpNewConnectionAcceptor::StartTcpNewConnectionAcceptorThread() {
    // Start thread
    if (pthread_create(
            this->accept_new_conn_thread,
            NULL,
            tcp_listen_for_new_connections,
            (void*) this)
    ) {
        printf("%s() Thread Creation failed, error = %d\n", __FUNCTION__, errno);
        exit(0);
    }

    printf("Service started: StartTcpNewConnectionAcceptorThread");
}
