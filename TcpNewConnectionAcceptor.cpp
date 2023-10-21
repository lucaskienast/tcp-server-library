//
// Created by Max Kienast on 17.10.23.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include "TcpServerController.h"
#include "TcpNewConnectionAcceptor.h"

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

void TcpNewConnectionAcceptor::StartTcpNewConnectionAcceptorThread() {

}
