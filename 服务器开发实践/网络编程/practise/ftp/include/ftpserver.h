#ifndef FTPSERVER_H
#define FTPSERVER_H

#include "Sockaddr.h"
#include <string>
#include <unordered_map>
#include <thread>
#include <functional>

namespace yuri::web {

class FtpServer {
  using sock_t = unsigned long int;

private:
  // 从指定fd中接受数据
  int recv_(const int client, char *buf, sock_t size);

  // 接受数据
  void recv(const int client);

public:
  FtpServer(const sock_t port, const std::string ip = "any");
  virtual ~FtpServer();

  // 开启监听本地端口
  bool listen();

  // 连接一个客户端并返回fd
  int accept();

  // 向指定client 发送信息
  bool writeToClient(const int client, const std::string msg);

  // 获取文件
  std::string readFile(const std::string &file_name);


private:
  int fd;                                       // socket 描述符
  Sockaddr addr;                                // 地址
  std::unordered_map<int, Sockaddr> users;      // 用户
  std::unordered_map<int, std::thread> threads; // 线程
};

} // namespace yuri

#endif
