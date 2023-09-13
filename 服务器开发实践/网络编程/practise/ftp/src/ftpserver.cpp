#include "../include/ftpserver.h"
#include <iterator>
#include <memory>
#include <sstream>
#include <fstream>

namespace yuri::web {

FtpServer::FtpServer(const sock_t port, const std::string ip) :
  fd(-2078), addr({}) {
  if (ip == "any") {
    addr.setAddress(INADDR_ANY);
  } else {
    addr.setAddress(ip);
  }
  addr.setPort(port);
}

FtpServer::~FtpServer() {
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

bool FtpServer::listen() {
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

int FtpServer::accept() {
  Sockaddr client_addr;
  int client = ::accept(fd, client_addr.addr(), addr.size_p());
  if (client <= 0) {
    error << "监听客户端失败!";
    error << strerror(errno);
    return -1;
  }
  struct timeval timeout;
  timeout.tv_sec = 5;
  timeout.tv_usec = 0;
  if (setsockopt(client, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
    perror("setsockopt");
    return 1;
  }

  users[client] = client_addr; // 添加进map
  info << "客户端 -> " << client << " 已经连接 ! ";
  users[client].setStatus(SocketState::客户端);
  client_addr.showInfo();
  // 创建新线程接受信息
  threads[client] = std::thread([this, client]() {
    this->recv(client);
  });
  return client;
}

// 向指定client 发送信息
bool FtpServer::writeToClient(const int client, const std::string msg) {
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

int FtpServer::recv_(const int client, char *buf, sock_t size) {
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
void FtpServer::recv(const int client) {
  while (true) {
    std::stringstream msg;
    sock_t size;
    // 接收需要读取的大小
    if (recv_(client, reinterpret_cast<char *>(&size), sizeof(sock_t)) > 1) {
      info << "本次接收 -> " << size;
      while (size > 0) {
        char buff[1024]{};
        int ret = recv_(client, buff, 1023);
        if (ret == 0) {
          error << "接收到0";
          exit(1);
        }
        size -= ret;
        msg.write(buff, ret);
      }
      info << "本次获取 -> " << msg.str().size();
      
      if (msg.str().size() > 100) {
        info << "本次接收是文件，正在写入!";
        std::fstream file("2.jpg", std::ios::out | std::ios::binary);
        file << msg.rdbuf();
        file.close();
      } else {
        info << "data ---------------> \n"
           << msg.str();
      }
    } else {
      return;
    }
  }
}

std::string FtpServer::readFile(const std::string &file_name) {
  std::ifstream file(file_name, std::ios::binary);
  if (!file) {
    error << "未找到文件 -> " << file_name;
    return "";
  }
  std::ostringstream buffer;
  buffer << file.rdbuf();
  file.close();
  return buffer.str();
}
} // namespace yuri::web