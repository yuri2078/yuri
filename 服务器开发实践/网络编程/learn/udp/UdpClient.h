#ifndef UDOCLIENT_H
#define UDOCLIENT_H

#include "Sockaddr.h"
#include <sys/socket.h>
#include <unordered_map>
#include <thread>

class UdpClient {
  using sock_t = unsigned short int;


public:
  UdpClient(const sock_t port, const std::string ip = "127.0.0.1") :
    fd(-2078), addr({}) {
    addr.setAddress(ip);
    addr.setPort(port);
  }

  ~UdpClient() {
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
    std::string msg_ = std::format("fd -> {} msg -> {}", fd, msg);
    int ret = ::sendto(fd, msg_.c_str(), msg_.size(), 0, addr.addr(), addr.size());
    if (ret < 0) {
      error << "发送信息失败:fd -> " << fd;
    }
    return true;
  }

private:
  int fd;                                       // socket 描述符
  Sockaddr addr;                                // 地址
  std::unordered_map<int, std::thread> threads; // 线程

  // 开启监听本地端口
  bool init() {
    // 创建socket
    fd = ::socket(AF_INET, SOCK_DGRAM, 0);
    if (fd <= 0) {
      error << "创建socket 失败!";
      error << strerror(errno);
      return false;
    }
    return true;
  }
};

#endif