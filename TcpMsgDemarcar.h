//
// Created by Max Kienast on 19.11.23.
//

#ifndef TCP_IP_SERVER_TCPMSGDEMARCAR_H
#define TCP_IP_SERVER_TCPMSGDEMARCAR_H


#include <stdint.h>
#define DEFAULT_CBC_SIZE 10240

typedef enum TcpMsgDemarcarType_ {
    TCP_DEMARCAR_NONE,
    TCP_DEMARCAR_FIXED_SIZE,
    TCP_DEMARCAR_VARIABLE_SIZE,
    TCP_DEMARCAR_PATTERN
};

typedef struct ByteCircularBuffer_ ByteCircularBuffer_t;
class TcpClient;

class TcpMsgDemarcar {

private:

protected:
    ByteCircularBuffer_t *bcb;
    unsigned char *buffer;

public:
    virtual bool IsBufferReadyToFlush() = 0;
    virtual void ProcessClientMsg(TcpClient *) = 0;

    TcpMsgDemarcar(uint16_t circular_buffer_len);
    TcpMsgDemarcar();
    ~TcpMsgDemarcar();

    void Destroy();
    void ProcessMsg(TcpClient *tcpClient, unsigned  char *msg_recvd, uint16_t msg_size);



};


#endif //TCP_IP_SERVER_TCPMSGDEMARCAR_H
