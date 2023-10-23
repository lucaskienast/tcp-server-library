//
// Created by Max Kienast on 17.10.23.
//

#include "TcpClient.h"

TcpClient::TcpClient(uint32_t ip_addr, uint16_t port_no) {
    this->ip_addr = ip_addr;
    this->port_no = port_no;
}

TcpClient::~TcpClient() {
}