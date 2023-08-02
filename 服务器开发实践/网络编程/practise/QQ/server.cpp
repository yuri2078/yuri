#include <iostream>
#include "./include/UdpServer.h"

int main() {
  UdpServer server(2078);
  server.recv();
  return 0;
}
