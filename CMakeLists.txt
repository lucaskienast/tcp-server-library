cmake_minimum_required(VERSION 3.24)
project(TCP_IP_Server)

set(CMAKE_CXX_STANDARD 17)

add_executable(TCP_IP_Server testapp.cpp TcpServerController.cpp TcpServerController.h TcpNewConnectionAcceptor.cpp TcpNewConnectionAcceptor.h TcpClientDbManager.cpp TcpClientDbManager.h TcpClientServiceManager.cpp TcpClientServiceManager.h TcpClient.cpp TcpClient.h network_utils.cpp network_utils.h tcp_client.cpp tcp_client_string_sender.cpp ByteCircularBuffer.cpp ByteCircularBuffer.h TcpMsgDemarcar.cpp TcpMsgDemarcar.h TcpMsgFixedSizeDemarcar.cpp TcpMsgFixedSizeDemarcar.h TcpMsgVariableSizeDemarcar.cpp TcpMsgVariableSizeDemarcar.h)
