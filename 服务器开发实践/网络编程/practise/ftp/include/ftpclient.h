#ifndef FTPCLIENT_H
#define FTPCLIENT_H

#include "Sockaddr.h"
#include <sys/socket.h>

namespace yuri::web {
class FtpClient {
  using sock_t = unsigned long int;

public:
  FtpClient(const std::string& ip,const sock_t port);

  ~FtpClient();

  // 连接到客户端
  bool connect();

  // 向客户端发送数据
  bool writeToServer(const std::string &msg);

  // 向服务器发送文件
  bool sendFile(const std::string &file_name);

private:
  Sockaddr addr; // 地址
  int fd; // 套接字
};
}


#endif