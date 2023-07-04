#include "TcpClient.h"
#include <source_location>

int main() {
  TcpClient client("127.0.0.1", 2078);
  if (client.connect() == false) {
    return 1;
  }
  std::cout << "成功连接服务器! 输入消息按回车结束, 推出请输入bye\n";
  while (true) {
    std::string msg;
    std::cin >> msg;
    if (msg == "bye") {
      break;
    }
    client.writeToServer(msg);
  }
  
  return 0;
}