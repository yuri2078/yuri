#include <iostream>
#include "./include/UdpClient.h"
#include <memory>

int main(const int argc, const char **argv) {
  if (argc < 2) {
    error << "请添加用户名!\n";
    return 1;
  }
  UdpClient client(2078);
  if (client.login(argv[1])) {
    info << "登陆成功，请发送消息， 按回车发送!bye退出!";
    std::string msg;
    while (msg != "bye") {
      std::cin >> msg;
      client.send(msg);
    }
  } else {
    error << "登陆失败！, 用户名已经存在!";
  }
  return 0;
}
