//
// Created by Max Kienast on 17.10.23.
//

#include <iostream>
#include <stdio.h>
#include <assert.h>
#include "TcpNewConnectionAcceptor.h"
#include "TcpClientDbManager.h"
#include "TcpClientServiceManager.h"
#include "TcpServerController.h"
#include "network_utils.h"

TcpServerController::TcpServerController(
        std::string ip_addr,
        uint16_t port_no,
        std::string name) {

    this->ip_addr = network_convert_ip_p_to_n(ip_addr.c_str());
    this->port_no = port_no;
    this->name = name;

    this->tcp_new_conn_acc = new TcpNewConnectionAcceptor(this);
    this->tcp_client_db_mgr = new TcpClientDbManager(this);
    this->tcp_client_svc_mgr = new TcpClientServiceManager(this);
}

TcpServerController::~TcpServerController(){

}

void TcpServerController::Start() {
    //... method body

    // For demonstration, let's print a message when this method is called
    std::cout << "Starting the TcpServerController..." << std::endl;

    // Other logic related to starting the server controller goes here...
}
