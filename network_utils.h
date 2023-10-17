//
// Created by Max Kienast on 17.10.23.
//

#ifndef TCP_IP_SERVER_NETWORK_UTILS_H
#define TCP_IP_SERVER_NETWORK_UTILS_H


#include <cstdint>

char* network_convert_ip_n_to_p(uint32_t ip_addr, char *output_buffer);

uint32_t network_convert_ip_p_to_n(const char *ip_addr);


#endif //TCP_IP_SERVER_NETWORK_UTILS_H
