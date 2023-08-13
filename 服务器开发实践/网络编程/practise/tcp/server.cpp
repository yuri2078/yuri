#include "./include/TcpServer.h"

int main() {
  TcpServer server(2078);
  if (server.listen() == false) {
    return 1;
  }
  
  while (true) {
    server.accept();
  }
  return 0;
}