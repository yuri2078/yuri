#ifndef SCOKADDR_H_Y
#define SCOKADDR_H_Y

#include <netinet/in.h>
#include <arpa/inet.h>
#include <format>
#include <cerrno>
#include <cstring>
#include <yuri.h>

enum SocketState { 未连接,
                   客户端,
                   服务端 };
class Sockaddr {
  using sock_t = unsigned short int;

public:
  // 创建并初始化
  Sockaddr() :
    addr_({}), len(sizeof(addr_)) {
    addr_.sin_family = AF_INET;
    state = SocketState::未连接;
  }

  void setStatus(const SocketState &new_state) {
    state = new_state;
  }

  SocketState getStatus() const {
    return state;
  }

  // 返回 sockaddr *
  sockaddr *addr() {
    return reinterpret_cast<sockaddr *>(&addr_);
  }

  // 设置端口号
  void setPort(const sock_t port) {
    addr_.sin_port = htons(port);
  }

  // 设置ip地址
  void setAddress(const std::string ip) {
    addr_.sin_addr.s_addr = inet_addr(ip.c_str());
    if (addr_.sin_addr.s_addr == INADDR_NONE) {
      error << "ip 地址转换错误!";
    }
  }

  void setAddress(const unsigned long int ip) {
    addr_.sin_addr.s_addr = htonl(ip);
    if (addr_.sin_addr.s_addr == INADDR_NONE) {
      error << "ip 地址转换错误!";
    }
  }

  // 获取端口号
  sock_t getPort() const {
    return ntohs(addr_.sin_port);
  }

  // 返回地址大小
  socklen_t size() const {
    return len;
  }

  // 返回地址大小的指针
  socklen_t *size_p() {
    return &len;
  }

  // 获取ip地址
  std::string getAddress() {
    return std::string(inet_ntoa(addr_.sin_addr));
  }

  // 展示信息
  void showInfo() {
    std::cout << std::format("ip -> {}, port -> {}\n", getAddress(), getPort());
  }

  // 重置
  void clear() {
    addr_ = {};
    len = sizeof(addr_);
  }

private:
  sockaddr_in addr_;
  socklen_t len;
  SocketState state;
};

#endif
