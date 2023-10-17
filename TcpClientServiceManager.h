//
// Created by Max Kienast on 17.10.23.
//

#ifndef TCP_IP_SERVER_TCPCLIENTSERVICEMANAGER_H
#define TCP_IP_SERVER_TCPCLIENTSERVICEMANAGER_H


#include "TcpServerController.h"

class TcpClientServiceManager {

private:

public:
    TcpServerController *tcp_cntrlr;

    TcpClientServiceManager(TcpServerController *);
    ~TcpClientServiceManager();

};


#endif //TCP_IP_SERVER_TCPCLIENTSERVICEMANAGER_H
