//
// Created by Max Kienast on 17.10.23.
//

#ifndef TCP_IP_SERVER_TCPNEWCONNECTIONACCEPTOR_H
#define TCP_IP_SERVER_TCPNEWCONNECTIONACCEPTOR_H


#include "TcpServerController.h"

class TcpNewConnectionAcceptor {

private:

public:
    TcpServerController *tcp_ctrlr;
    TcpNewConnectionAcceptor(TcpServerController *);
    ~TcpNewConnectionAcceptor();

};


#endif //TCP_IP_SERVER_TCPNEWCONNECTIONACCEPTOR_H
