#ifndef UDOSERVER_H
#define UDOSERVER_H

#include "Sockaddr.h"
#include "message.h"
#include <unordered_map>
#include <functional>
#include <utility>

class UdpServer {
  using sock_t = unsigned short int;

public:
  UdpServer(const sock_t port, const std::string ip = "any") :
    fd(-2078), addr({}) {
    initFunc();
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
      return false;
    }
    char head_[sizeof(MessageHead)];
    if (recv(head_, sizeof(MessageHead)) > 0) {
      MessageHead *head = reinterpret_cast<MessageHead *>(head_);
      func[head->type()]();
    }
    return true;
  }

private:
  int fd;        // socket 描述符
  Sockaddr addr; // 地址
  std::unordered_map<MessageType, std::function<void()>> func;

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

  int recv(char *data, sock_t size) {
    int ret = ::recvfrom(fd, data, size, 0, addr.addr(), addr.size_p());
    if (ret < 0) {
      error << "获取信息失败!";
    } else if (ret == 0) {
      info << "对方关闭连接!";
    }
    return ret;
  }

  void initFunc() {
    func[MessageType::login] = []() {
      info << "这是登陆消息!\n";
    };

    func[MessageType::msg] = []() {
      info << "这是普通消息!\n";
    };

    func[MessageType::config] = []() {
      info << "这是配置消息!\n";
    };
  }
};

#endif
