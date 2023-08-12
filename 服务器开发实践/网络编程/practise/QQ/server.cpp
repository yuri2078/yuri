#include <iostream>
#include "./include/UdpServer.h"

int main() {
  UdpServer server(2078);
  while (true) {
    server.recv();
  }

  return 0;
}
