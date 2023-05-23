#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include "Sockaddr.h"
#include <sys/socket.h>

class TcpClient {
  using sock_t = unsigned short int;

public:
  TcpClient(const std::string ip,const sock_t port) : addr({}), fd(-666)
  {
    addr.setAddress(ip);
    addr.setPort(port);
  }

  ~TcpClient() {
    if (fd != -666) {
      ::close(fd);
    }
  }

  // 连接到客户端
  bool connect() {
    fd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (fd <= 0) {
      error("创建socket 失败!");
      error(strerror(errno));
      return false;
    }
    int ret = ::connect(fd, addr.addr(), addr.size());
    if (ret == -1) {
      error("连接客户端失败!");
      error(strerror(errno));
    }
    return false;
  }

  // 向客户端发送数据
  bool write(const std::string msg) {
    if (fd == -666) {
      error("套接字没有连接!");
      return false;
    }
    if (::send(fd, msg.c_str(), msg.size(), 0) <= 0) {
      error("写入数据失败!");
      error(strerror(errno));
    }
    return true; 
  }

private:
  Sockaddr addr; // 地址
  int fd; // 套接字
};

#endif