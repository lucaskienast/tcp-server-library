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

void TcpClientDbManager::AddClientToDb(TcpClient *tcp_client) {
    this->tcp_client_db.push_back(tcp_client);
}