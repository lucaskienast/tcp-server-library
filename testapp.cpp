#include "TcpServerController.h"

int main() {

    TcpServerController *server1 = new TcpServerController(
            "127.0.0.1",
            40000,
            "Default TCP Server");

    server1->Start();

    scanf("\n");

    return 0;
}
