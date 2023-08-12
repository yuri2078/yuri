#ifndef UDOCLIENT_H
#define UDOCLIENT_H

#include "Sockaddr.h"
#include <memory>
#include <sys/socket.h>
#include "message.h"
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

  bool login(const std::string &username) {
    send(username, MessageType::login);
    int ret;
    if (!recv(reinterpret_cast<char *>(&ret), sizeof(ret))) {
      return false;
    }
    if (ret > 0) {
      id = ret;
    } else {
      error << "登陆失败! 错误码 -> " << ret;
      return false;
    }
    return ret > 0;
  }

  bool send(const std::string &msg) {
    return send(msg, MessageType::msg);
  }

private:
  int fd; // socket 描述符
  int id; // 身份id
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

  bool send(const std::string &msg, const MessageType &type) {
    MessageHead head(msg.size(), type);
    head.setId(id);
    if (send(head.headData(), sizeof(MessageHead))) {
      send(msg.c_str(), msg.size());
    }
    return true;
  }

  bool recv(char *data, const unsigned size) {
    int ret = ::recvfrom(fd, data, size, 0, addr.addr(), addr.size_p());
    if (ret < 0) {
      error << "获取信息失败:fd -> " << fd;
    } else if (ret == 0) {
      error << "对方关闭链接!";
    }
    return ret > 0;
  }

  bool send(const char *data, sock_t size) {
    if (fd == -2078 && !init()) {
      error << "绑定套接字失败!";
      return "";
    }
    int ret = ::sendto(fd, data, size, 0, addr.addr(), addr.size());
    if (ret < 0) {
      error << "发送信息失败:fd -> " << fd;
    }
    return true;
  }

};

#endif