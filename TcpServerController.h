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
class TcpClient;

class TcpServerController {

private:
    TcpNewConnectionAcceptor *tcp_new_conn_acc;
    TcpClientDbManager *tcp_client_db_mgr;
    TcpClientServiceManager *tcp_client_svc_mgr;

public:
    uint32_t ip_addr;
    uint16_t port_no;
    std::string name;

    void(*client_connected)(const TcpServerController *, const TcpClient *);
    void(*client_disconnected)(const TcpServerController *, const TcpClient *);
    void(*client_msg_received)(const TcpServerController *, const TcpClient *, unsigned char *, uint16_t);

    void SetServerNotifyCallbacks(
        void(*client_connected)(const TcpServerController *, const TcpClient *),
        void(*client_disconnected)(const TcpServerController *, const TcpClient *),
        void(*client_msg_received)(const TcpServerController *, const TcpClient *, unsigned char *, uint16_t)
    );

    TcpServerController(std::string ip_addr, uint16_t port_no, std::string name);

    ~TcpServerController();

    void Start();
    void Stop();
    void ProcessNewClient(TcpClient *tcp_client);
    void Display();
};


#endif //TCP_IP_SERVER_TCPSERVERCONTROLLER_H
