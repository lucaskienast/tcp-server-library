//
// Created by Max Kienast on 17.10.23.
//

#include "TcpServerController.h"
#include "TcpClientDbManager.h"

TcpClientDbManager::TcpClientDbManager(TcpServerController *tcp_ctrlr) {
    this->tcp_ctrlr = tcp_ctrlr;
}

TcpClientDbManager::~TcpClientDbManager(){
}

void TcpClientDbManager::StartTcpClientDbManagerThread() {

}
