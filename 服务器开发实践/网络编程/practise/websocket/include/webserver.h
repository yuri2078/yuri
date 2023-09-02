#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include "Sockaddr.h"
#include <string>
#include <unordered_map>
#include <thread>
#include <functional>
#include "response.h"
#include "request.h"
#include "type.h"

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

  // 向指定client服务端 发送状态为status 类型为type 的msg消息
  void result(int client, web::Status status, web::ContentType type, std::string msg);

public:
  WebServer(const sock_t port, const std::string ip = "any");
  virtual ~WebServer();

  // 开启监听本地端口
  bool listen();

  // 连接一个客户端并返回fd
  int accept();

  // 向指定client 发送信息
  bool writeToClient(const int client, const std::string msg);

  // 获取文件
  std::string readFile(const std::string &file_name);

  // 注册路径处理 get
  void getMapping(std::string path, std::function<void(int client)> func);

  

private:
  int fd;                                       // socket 描述符
  Sockaddr addr;                                // 地址
  std::unordered_map<int, Sockaddr> users;      // 用户
  std::unordered_map<int, std::thread> threads; // 线程
  std::unordered_map<std::string, std::function<void(int client)>> get_func; // 路径处理函数
  std::unordered_map<std::string, std::function<void(int client)>> post_func; // 路径处理函数
};

} // namespace yuri

#endif
