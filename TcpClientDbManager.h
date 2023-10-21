//
// Created by Max Kienast on 17.10.23.
//

#ifndef TCP_IP_SERVER_TCPCLIENTDBMANAGER_H
#define TCP_IP_SERVER_TCPCLIENTDBMANAGER_H


#include <list>
class TcpServerController;
class TcpClient;

class TcpClientDbManager {

private:
    std::list<TcpClient *>tcp_client_db;

public:
    TcpServerController *tcp_ctrlr;

    TcpClientDbManager(TcpServerController *);
    ~TcpClientDbManager();

    void StartTcpClientDbManagerThread();

};


#endif //TCP_IP_SERVER_TCPCLIENTDBMANAGER_H
