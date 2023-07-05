#ifndef UDOSERVER_H
#define UDOSERVER_H

#include "Sockaddr.h"
#include <sys/socket.h>
#include <unordered_map>
#include <thread>

class UdpServer {
  using sock_t = unsigned short int;


public:

  UdpServer(const sock_t port, const std::string ip = "any") :
    fd(-2078), addr({}) {
    if (ip == "any") {
      addr.setAddress(INADDR_ANY);
    } else {
      addr.setAddress(ip);
    }
    addr.setPort(port);
  }


  ~UdpServer() {
    if (thread.joinable()) {
      thread.join();
    }

    if (fd != -2078) {
      ::close(fd);
    }
  }

  std::string recvFrom() {
    if (fd == -2078 && !init()) {
      error << "绑定套接字失败!";
      return "";
    }
    char buf[1024]{};
    int ret = ::recvfrom(fd, buf, 1024, 0, addr.addr(), addr.size_p());
    if (ret < 0) {
      error << "获取信息失败:fd -> " << fd;
    }

    info << "msg -> " << buf;
    return std::string(buf);
  }

  bool sendTo(const std::string &msg) {
    if (fd == -2078 && !init()) {
      error << "绑定套接字失败!";
      return "";
    }
    
    int ret = ::sendto(fd, msg.c_str(), msg.size(), 0, addr.addr(), addr.size());
    if (ret < 0) {
      error << "发送信息失败:fd -> " << fd;
    }
    return true;
  }

  void startToListen() {
    thread = std::thread([this]() {
      while(true) {
        if(this->recvFrom() == "") {
          error << "获取信息失败,退出程序!";
          return;
        }
      }
    });
  }

private:
  int fd; // socket 描述符
  Sockaddr addr; // 地址
  std::thread thread;

  // 开启监听本地端口
  bool init() {
    // 创建socket
    fd = ::socket(AF_INET, SOCK_DGRAM, 0);
    if (fd <= 0) {
      error << "创建socket 失败!";
      error << strerror(errno);
      return false;
    }

    // 绑定本地ip 地址
    if (::bind(fd, addr.addr(), addr.size()) == -1) {
      error << "绑定地址失败!";
      error << strerror(errno);
      return false;
    }

    info << fd << " 正在监听 ip -> " << addr.getAddress() << " " << addr.getPort();
    return true;
  }
};
  
#endif