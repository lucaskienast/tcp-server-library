//
// Created by Max Kienast on 17.10.23.
//

#ifndef TCP_IP_SERVER_TCPSERVERCONTROLLER_H
#define TCP_IP_SERVER_TCPSERVERCONTROLLER_H


#include <cstdint>
#include <string>
class TcpNewConnectionAcceptor;
class TcpClientServiceManager;
class TcpClientDbManager;

class TcpServerController {

private:
    TcpNewConnectionAcceptor *tcp_new_conn_acc;
    TcpClientDbManager *tcp_client_db_mgr;
    TcpClientServiceManager *tcp_client_svc_mgr;

public:
    uint32_t ip_addr;
    uint16_t port_no;
    std::string name;

    TcpServerController(std::string ip_addr, uint16_t port_no, std::string name);

    ~TcpServerController();

    void Start();
    void Stop();
};


#endif //TCP_IP_SERVER_TCPSERVERCONTROLLER_H
