CC=g++
CFLAGS=-g
TARGET:testapp.exe
LIBS=-lpthread
OBJS=TcpClientDBManager.o 		 		\
			TcpMsgFixedSizeDemarcar.o 		 \
			TcpMsgDemarcar.o 		 \
			TcpClientServiceManager.o 		 \
			TcpNewConnectionAcceptor.o 	 \
			TcpServerController.o 				  \
			TcpClient.o 				  \
			tcp_client.o 				  \
			network_utils.o

testapp.exe:testapp.o ${OBJS}
	${CC} ${CFLAGS} ${OBJS} testapp.o -o testapp.exe ${LIBS}

testapp.o:testapp.cpp
	${CC} ${CFLAGS} -c testapp.cpp -o testapp.o

TcpClientDBManager.o:TcpClientDBManager.cpp
	${CC} ${CFLAGS} -c TcpClientDBManager.cpp -o TcpClientDBManager.o

TcpClientServiceManager.o:TcpClientServiceManager.cpp
	${CC} ${CFLAGS} -c TcpClientServiceManager.cpp -o TcpClientServiceManager.o

TcpNewConnectionAcceptor.o:TcpNewConnectionAcceptor.cpp
	${CC} ${CFLAGS} -c TcpNewConnectionAcceptor.cpp -o TcpNewConnectionAcceptor.o

TcpServerController.o:TcpServerController.cpp
	${CC} ${CFLAGS} -c TcpServerController.cpp -o TcpServerController.o

TcpClient.o:TcpClient.cpp
	${CC} ${CFLAGS} -c TcpClient.cpp -o TcpClient.o

tcp_client.o:tcp_client.cpp
	${CC} ${CFLAGS} -c tcp_client.cpp -o tcp_client.o

network_utils.o:network_utils.cpp
	${CC} ${CFLAGS} -c network_utils.cpp -o network_utils.o

network_utils.o:tcp_client_string_sender.cpp
	${CC} ${CFLAGS} -c tcp_client_string_sender.cpp -o tcp_client_string_sender.o

TcpMsgFixedSizeDemarcar.o:TcpMsgFixedSizeDemarcar.cpp
	${CC} ${CFLAGS} -c TcpMsgFixedSizeDemarcar.cpp -o TcpMsgFixedSizeDemarcar.o

TcpMsgDemarcar.o:TcpMsgDemarcar.cpp
	${CC} ${CFLAGS} -c TcpMsgDemarcar.cpp -o TcpMsgDemarcar.o

clean:
	rm -f *.o
	rm -f *exe
