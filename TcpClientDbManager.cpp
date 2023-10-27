//
// Created by Max Kienast on 17.10.23.
//

#include "TcpServerController.h"
#include "TcpClientDbManager.h"
#include "TcpClient.h"

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

void TcpClientDbManager::DisplayClientDb() {
    TcpClient *tcp_client;
    std::list<TcpClient*>::iterator it;

    for (it = this->tcp_client_db.begin(); it != this->tcp_client_db.end(); ++it) {
        tcp_client = *it;
        tcp_client->Display();
    }
}