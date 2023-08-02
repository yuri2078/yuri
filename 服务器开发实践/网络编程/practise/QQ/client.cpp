#include <iostream>
#include "./include/UdpClient.h"
#include <memory>

int main() {
  UdpClient client(2078);
  client.sendTo("yuri is yes");
  // std::unique_ptr<Message> ptr = std::make_unique<Message>("yuri", "yuri");
  return 0;
}
