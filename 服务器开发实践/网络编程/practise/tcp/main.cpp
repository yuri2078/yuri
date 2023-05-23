#include "TcpServer.h"

int main() {
  TcpServer server(2078);
  server.listen();
  server.accept();
  return 0;
}