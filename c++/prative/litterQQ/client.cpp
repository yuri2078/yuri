#include <iostream>
#include <yuri/TcpClient.h>

int main() {
  TcpClient client("127.0.0.1", 2078);
  if (!client.connect()) {
    return 1;
  }
  return 0;
}