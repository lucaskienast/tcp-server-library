//
// Created by Max Kienast on 17.10.23.
//

#ifndef TCP_IP_SERVER_TCPCLIENTSERVICEMANAGER_H
#define TCP_IP_SERVER_TCPCLIENTSERVICEMANAGER_H


#include <locale>
#include <list>

class TcpServerController;

class TcpClientServiceManager {

private:
    int max_fd;
    fd_set active_fd_set;
    fd_set backup_fd_set;
    pthread_t *client_svc_mgr_thread;
    std::list<TcpClient *> tcp_client_db;

public:
    TcpServerController *tcp_ctrlr;

    TcpClientServiceManager(TcpServerController *);
    ~TcpClientServiceManager();

    void StartTcpClientServiceManagerThread();
    void StopTcpClientServiceManagerThread();
    void StartTcpClientServiceManagerThreadInternal();
    void ClientFdStartListen(TcpClient *);
    void CopyClientFDtoFDSet(fd_set *fdset);
    int GetMaxFd();
    TcpClient* LookUpClientDB(uint32_t ip_addr, uint16_t port_no);
    void AddClientToDB(TcpClient *tcp_client);
};


#endif //TCP_IP_SERVER_TCPCLIENTSERVICEMANAGER_H
