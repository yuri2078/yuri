#include <iostream>
#include <yuri/TcpServer.h>

int main() {
  TcpServer server(2078);
  if (server.listen()) {
    while (true) {
      server.accept();
    }
  }
  return 0;
}