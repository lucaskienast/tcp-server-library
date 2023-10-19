//
// Created by Max Kienast on 17.10.23.
//

#include "TcpServerController.h"
#include "TcpNewConnectionAcceptor.h"

TcpNewConnectionAcceptor::TcpNewConnectionAcceptor(TcpServerController *tcp_ctrlr) {
    this->tcp_ctrlr = tcp_ctrlr;
}

TcpNewConnectionAcceptor::~TcpNewConnectionAcceptor(){
}