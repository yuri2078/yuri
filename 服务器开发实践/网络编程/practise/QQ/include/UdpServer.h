#ifndef UDOSERVER_H
#define UDOSERVER_H

#include "Sockaddr.h"
#include "message.h"
#include <unordered_map>
#include <functional>
#include <memory>

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
      func[head->type()](std::make_shared<MessageHead>(*head));
    }
    return true;
  }

private:
  int fd;        // socket 描述符
  Sockaddr addr; // 地址
  std::unordered_map<MessageType, std::function<void(std::shared_ptr<MessageHead>)>> func;
  std::unordered_map<int, std::string> users;

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
    func[MessageType::login] = [this](const std::shared_ptr<MessageHead> head) {
      head->setSize(head->size());
      if(this->recv(head->msgData(), head->size())) {
        int ret(addUser(head->msg()));
        if (ret > 0) {
          info << "用户 -> " << head->msg() << " 登陆成功!";
        }
        send(reinterpret_cast<char *>(&ret), sizeof(ret));
      }
    };

    func[MessageType::msg] = [this](const std::shared_ptr<MessageHead> head) {
      head->setSize(head->size());
      if(this->recv(head->msgData(), head->size())) {
        info << users[head->id()] << " : " << head->msg();
      }
    };

    func[MessageType::config] = [this](const std::shared_ptr<MessageHead> head) {
      info << "这是配置消息!";
    };
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

  int addUser(const std::string &username) {
    for (auto begin = users.begin(); begin != users.end(); begin++) {
      if (begin->second == username) {
        return -1;
      }
    }
    users[users.size() + 1] = username;
    return users.size();
  }
};

#endif
