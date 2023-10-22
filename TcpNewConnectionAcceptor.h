//
// Created by Max Kienast on 17.10.23.
//

#ifndef TCP_IP_SERVER_TCPNEWCONNECTIONACCEPTOR_H
#define TCP_IP_SERVER_TCPNEWCONNECTIONACCEPTOR_H


class TcpServerController;

/* New connections are accepted using accept() sys call
 * Create file descriptor accept_fd using socket() sys call
 * */
class TcpNewConnectionAcceptor {

private:
    int accept_fd;
    pthread_t *accept_new_conn_thread;
public:
    TcpServerController *tcp_ctrlr;
    TcpNewConnectionAcceptor(TcpServerController *);
    ~TcpNewConnectionAcceptor();

    void StartTcpNewConnectionAcceptorThread();
    void StartTcpNewConnectionAcceptorThreadInternal();
};


#endif //TCP_IP_SERVER_TCPNEWCONNECTIONACCEPTOR_H
