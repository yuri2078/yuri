#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include "Sockaddr.h"
#include <unordered_map>
#include <thread>
#include <functional>
#include "httptype.h"
#include "response.h"

namespace yuri {

class WebServer {
  using sock_t = unsigned short int;

private:
  // 从指定fd中接受数据
  int recv_(const int client, char *buf, sock_t size);

  // 接受数据
  void recv(const int client);

  // 初始化处理函数
  void init();

public:
  WebServer(const sock_t port, const std::string ip = "any");
  virtual ~WebServer();

  // 开启监听本地端口
  bool listen();

  // 连接一个客户端并返回fd
  int accept();

  // 向指定client 发送信息
  bool writeToClient(const int client, const std::string msg);

private:
  int fd;                                       // socket 描述符
  Sockaddr addr;                                // 地址
  std::unordered_map<int, Sockaddr> users;      // 用户
  std::unordered_map<int, std::thread> threads; // 线程
};

} // namespace yuri

#endif
