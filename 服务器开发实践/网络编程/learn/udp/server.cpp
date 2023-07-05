#include "UdpServer.h"

int main() {
  UdpServer server(2078);
  server.startToListen();
  while (true) {
    std::string msg;
    std::cin >> msg;
    if (msg == "bye") {
      break;
    }

    server.sendTo(msg);
  }
  return 0;

}
