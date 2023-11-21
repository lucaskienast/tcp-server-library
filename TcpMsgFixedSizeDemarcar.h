//
// Created by Max Kienast on 20.11.23.
//

#ifndef TCP_IP_SERVER_TCPMSGFIXEDSIZEDEMARCAR_H
#define TCP_IP_SERVER_TCPMSGFIXEDSIZEDEMARCAR_H

#include <stdint.h>
#include "TcpMsgDemarcar.h"

class TcpClient;


class TcpMsgFixedSizeDemarcar: public TcpMsgDemarcar {

private:
    uint16_t msg_fixed_size;

public:
    bool IsBufferReadyToFlush();
    void ProcessClientMsg(TcpClient *tcp_client);

    TcpMsgFixedSizeDemarcar(uint16_t fixed_size);
    ~TcpMsgFixedSizeDemarcar();

    void Destroy();

};


#endif //TCP_IP_SERVER_TCPMSGFIXEDSIZEDEMARCAR_H
