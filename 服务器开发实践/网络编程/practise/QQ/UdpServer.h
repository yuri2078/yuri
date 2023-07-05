#ifndef UDOSERVER_H
#define UDOSERVER_H

#include "Sockaddr.h"
#include "message.h"

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
    if (fd != -2078) {
      ::close(fd);
    }
  }

  bool recv() {
    if (fd <= 0 && !init()) {
      
    }
    return true;
  }

  

private:
  int fd; // socket 描述符
  Sockaddr addr; // 地址

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