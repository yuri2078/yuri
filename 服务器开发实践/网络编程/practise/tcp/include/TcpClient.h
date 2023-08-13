#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include "Sockaddr.h"
#include <sys/socket.h>

class TcpClient {
  using sock_t = unsigned short int;

public:
  TcpClient(const std::string ip,const sock_t port) : addr({}), fd(-2078)
  {
    addr.setAddress(ip);
    addr.setPort(port);
  }

  ~TcpClient() {
    if (fd != -2078) {
      ::close(fd);
    }
  }

  // 连接到客户端
  bool connect() {
    fd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (fd <= 0) {
      error << "创建socket 失败!" ;
      error << strerror(errno);
      return false;
    }
    int ret = ::connect(fd, addr.addr(), addr.size());
    if (ret == -1) {
      error << "连接客户端失败!";
      error << strerror(errno);
      return false;
    }
    info << "连接到服务端 -> " << fd;
    return true;
  }

  // 向客户端发送数据
  bool writeToServer(const std::string msg) {
    if (fd == -666) {
      error << "套接字没有连接!";
      return false;
    }

    sock_t size = msg.size();
    if (::send(fd, &size, sizeof(sock_t), 0) <= 0) {
      error << "写入数据长度失败!";
      error << strerror(errno);
      return false;
    }

    if (::send(fd, msg.c_str(), msg.size(), 0) <= 0) {
      error << "写入数据失败!";
      error << strerror(errno);
      return false;
    }
    return true; 
  }

private:
  Sockaddr addr; // 地址
  int fd; // 套接字
};

#endif