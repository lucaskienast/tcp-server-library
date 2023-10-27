//
// Created by Max Kienast on 17.10.23.
//

#ifndef TCP_IP_SERVER_TCPCLIENT_H
#define TCP_IP_SERVER_TCPCLIENT_H

#include <stdint.h>

class TcpServerController;


class TcpClient {

private:

public:
    TcpServerController *tcp_ctrlr;
    uint32_t ip_addr;
    uint16_t port_no;
    int comm_fd;

    TcpClient(uint32_t ip_addr, uint16_t port_no);
    ~TcpClient();

    void Display();

};


#endif //TCP_IP_SERVER_TCPCLIENT_H
