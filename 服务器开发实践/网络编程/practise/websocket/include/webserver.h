#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include "Sockaddr.h"
#include <string>
#include <sys/socket.h>
#include <unordered_map>
#include <thread>
#include "httptype.h"
#include "response.h"

namespace yuri {


class WebServer {
  using sock_t = unsigned short int;

private:
  int recv_(const int client, char *buf, sock_t size) {
    int ret = ::recv(client, buf, size, 0);
    if (ret == 0) {
      info << std::format("{} 断开连接!", client);
      users[client].setStatus(SocketState::未连接);
      return 0;
    }
    if (ret < 0) {
      error << "读取报文出错!";
      error << strerror(errno);
      return 0;
    }

    return ret;
  }
  // 接受数据
  void recv(const int client) {
    while (true) {
      char buff[1024]{};
      if (recv_(client, buff, 1024) > 0) {
        info << client << " -> " << buff;
        Response response(buff);
        std::string html = response.readFile("/home/yuri/yuri/服务器开发实践/网络编程/practise/websocket/dist/index.html");
        response.setContent(ContentType::html, html.size());
        writeToClient(client, response.httpHeader());
        writeToClient(client, html);
      } else {
        return;
      }
    }
  }

public:

  WebServer(const sock_t port, const std::string ip = "any") :
    fd(-2078), addr({}) {
    if (ip == "any") {
      addr.setAddress(INADDR_ANY);
    } else {
      addr.setAddress(ip);
    }
    addr.setPort(port);
  }


  ~WebServer() {
    if (fd != -2078) {
      ::close(fd);
    }

    // 结束僵尸线程并关闭连接释放资源
    for (auto iter = users.begin(); iter != users.end(); iter++) {
      if (threads[iter->first].joinable()) {
        threads[iter->first].join();
      }
      ::close(iter->first);
    }
  }


  // 开启监听本地端口
  bool listen() {
    // 创建socket
    fd = ::socket(AF_INET, SOCK_STREAM, 0);
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

    // 开启监听
    if (::listen(fd, 20) == -1) {
      error << "监听失败!";
      error << strerror(errno);
      return false;
    }
    info << fd << " 正在监听 ip -> " << addr.getAddress() << " " << addr.getPort();
    return true;
  }

  // 连接一个客户端并返回fd
  int accept() {
    Sockaddr client_addr;
    int client = ::accept(fd, client_addr.addr(), addr.size_p());
    if ( client <= 0) {
      error << "监听客户端失败!";
      error << strerror(errno);
      return -1;
    }

    users[client] = client_addr; // 添加进map
    std::cout << "客户端 -> " << client << " 已经连接 ! ";
    users[client].setStatus(SocketState::客户端);
    client_addr.showInfo();
    // 创建新线程接受信息
    threads[client] = std::thread([this, client]() {
      this->recv(client);
    });
    return client;
  }

  // 向指定client 发送信息
  bool writeToClient(const int client,const std::string msg) {
    if (users.find(client) == users.end() || users[client].getStatus() == SocketState::未连接) {
      error << "没有该用户,或者该用户已经断开连接!";
      return false;
    }

    int ret = ::send(client, msg.c_str(), msg.size(), 0);
    if (ret <= 0) {
      error << "发送失败!";
      error << strerror(errno);
      return false;
    }
    return true;
  }

private:
  int fd; // socket 描述符
  Sockaddr addr; // 地址
  std::unordered_map<int, Sockaddr> users; // 用户
  std::unordered_map<int, std::thread> threads; // 线程
};

} // namespace yuri

#endif
