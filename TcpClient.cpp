//
// Created by Max Kienast on 17.10.23.
//

#include <cstdlib>
#include <cstdio>
#include "TcpClient.h"
#include "network_utils.h"

TcpClient::TcpClient(uint32_t ip_addr, uint16_t port_no) {
    this->ip_addr = ip_addr;
    this->port_no = port_no;
}

TcpClient::~TcpClient() {
}

void TcpClient::Display() {
    printf("Tcp client: [%s, %d]\n",
           network_convert_ip_n_to_p(htonl(this->ip_addr), 0),
           htons(this->port_no));
}