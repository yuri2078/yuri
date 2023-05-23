#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "Sockaddr.h"
#include <sys/socket.h>
#include <unordered_map>
#include <thread>

class TcpServer {
  using sock_t = unsigned short int;

private:
  // 接受数据
  void recv(const int client) {
    while (true) {
      char buff[1024]{};
      int ret = ::recv(client, buff, 1024, 0);
      if (ret == 0) {
        info(std::format("{} 断开连接!", client));
        return;
      }

      if (ret < 0) {
        error("读取报文出错!");
        error(strerror(errno));
        continue;
      }

      buff[ret] = 0;
      // 打印数据
      std::cout << std::format("{} -> {}\n", client, buff);
    }
  }

public:
  // 构造函数
  TcpServer(const sock_t port, const std::string ip = "any") :
    fd(-666), addr({}) {
    if (ip == "any") {
      addr.setAddress(INADDR_ANY);
    } else {
      addr.setAddress("127.0.0.1");
    }
    addr.setPort(port);
  }

  ~TcpServer() {
    if (fd != -666) {
      ::close(fd);
    }

    // 结束僵尸线程并关闭连接释放资源
    for (auto iter = users.begin(); iter != users.end(); iter++) {
      threads[iter->first].join();
      ::close(iter->first);
    }
  }


  // 开启监听本地端口
  bool listen() {
    // 创建socket
    fd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (fd <= 0) {
      error("创建socket 失败!");
      error(strerror(errno));
      return false;
    }

    // 绑定本地ip 地址
    if (::bind(fd, addr.addr(), addr.size()) == -1) {
      error("绑定地址失败!");
      error(strerror(errno));
      return false;
    }

    // 开启监听
    if (::listen(fd, 20) == -1) {
      error("监听失败!");
      error(strerror(errno));
      return false;
    }
    
    return true;
  }

  // 连接一个客户端并返回fd
  int accept() {
    Sockaddr client_addr;
    int client = ::accept(fd, client_addr.addr(), addr.size_p());
    if ( client <= 0) {
      error("监听客户端失败!");
      error(strerror(errno));
      return -1;
    }

    users[client] = client_addr; // 添加进map
    std::cout << "客户端 -> " << client << " 已经连接 ! ";
    client_addr.showInfo();
    // 创建新线程接受信息
    threads[client] = std::thread([this, client]() {
      this->recv(client);
    });
    return client;
  }

  // 向指定client 发送信息
  bool write(const int client,const std::string msg) {
    if (users.find(client) == users.end()) {
      error("没有该用户,或者该用户已经断开连接!");
      return false;
    }

    int ret = ::send(client, msg.c_str(), msg.size(), 0);
    if (ret <= 0) {
      error("发送失败!");
      error(strerror(errno));
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

#endif