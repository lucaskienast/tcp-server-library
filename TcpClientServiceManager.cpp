//
// Created by Max Kienast on 17.10.23.
//

#include "TcpServerController.h"
#include "TcpClientServiceManager.h"

TcpClientServiceManager::TcpClientServiceManager(TcpServerController *tcp_ctrlr) {
    this->tcp_ctrlr = tcp_ctrlr;
}

TcpClientServiceManager::~TcpClientServiceManager(){
}

void TcpClientServiceManager::StartTcpClientServiceManagerThread() {

}

void TcpClientServiceManager::ClientDfStartListen(TcpClient *) {

}