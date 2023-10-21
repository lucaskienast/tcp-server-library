//
// Created by Max Kienast on 17.10.23.
//

#ifndef TCP_IP_SERVER_TCPCLIENTSERVICEMANAGER_H
#define TCP_IP_SERVER_TCPCLIENTSERVICEMANAGER_H


class TcpServerController;

class TcpClientServiceManager {

private:

public:
    TcpServerController *tcp_ctrlr;

    TcpClientServiceManager(TcpServerController *);
    ~TcpClientServiceManager();

    void StartTcpClientServiceManagerThread();

};


#endif //TCP_IP_SERVER_TCPCLIENTSERVICEMANAGER_H
