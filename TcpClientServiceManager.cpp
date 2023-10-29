//
// Created by Max Kienast on 17.10.23.
//

#include "TcpServerController.h"
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