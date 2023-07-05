#include "UdpClient.h"
#include "UdpServer.h"
#include <chrono>
#include <format>
#include <thread>

int main() {

  UdpClient client(2078);
  std::thread thread;
  thread = std::thread([&client]() {
    while(true) {
      if (client.recvFrom() == "") {
        error << "get message error!";
        return;
      }
    }
  });

  std::cout << "线程 id -> " << std::this_thread::get_id();

  while (true) {
    std::string msg;
    std::cin >> msg;
    if (msg == "bye") {
      break;
    }

    client.sendTo(msg);
  }


  if (thread.joinable()) {
    thread .join();
  }
  return 0;
}