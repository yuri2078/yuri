#include "TcpClient.h"

int main() {
  TcpClient client("127.0.0.1", 2078);
  client.connect();
  client.write("我是新的客户端");
  return 0;
}