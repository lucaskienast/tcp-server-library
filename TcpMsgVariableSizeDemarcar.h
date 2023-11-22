//
// Created by Max Kienast on 22.11.23.
//

#ifndef TCP_IP_SERVER_TCPMSGVARIABLESIZEDEMARCAR_H
#define TCP_IP_SERVER_TCPMSGVARIABLESIZEDEMARCAR_H

#include <stdint.h>
#include "TcpMsgDemarcar.h"

#define VARIABLE_SIZE_MAX_BUFFER 256

class TcpClient;

class TcpMsgVariableSizeDemarcar: public TcpMsgDemarcar {

private:
public:
    bool IsBufferReadyToFlush();
    void ProcessClientMsg(TcpClient *);

    TcpMsgVariableSizeDemarcar();
    ~TcpMsgVariableSizeDemarcar();
    void Destroy();

};


#endif //TCP_IP_SERVER_TCPMSGVARIABLESIZEDEMARCAR_H
