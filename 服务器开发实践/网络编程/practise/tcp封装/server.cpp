#include <sys/socket.h>
#include <yuri.h>

class Sockaddr {
  using sockaddr_in = struct sockaddr_in;
  using addr_t = unsigned short int;
  using string = std::string;

  Sockaddr() = default;
  ~Sockaddr() = default;
  

private:
  addr_t port; // 端口号
  addr_t family; // 协议族
  string ip;   // ip地址
};

class Server {
  using sockaddr_in = struct sockaddr_in;
  using addr_t = unsigned short int;
  using string = std::string;

public:
  Server() = default;
  ~Server() = default;

  // 默认监听所有ip地址下 2078端口的信息 默认6个人
  bool listen(addr_t port = 2078, const string &ip = "any", addr_t size = 6) {
    this->port = port;
    this->ip = ip;
    if (init()) {
      int ret = ::listen(fd, size);
      if (ret == -1) {
        error("设置监听模式失败!")
      }
    }

    return false;
  }

  bool accept() {
    info("开始获取用户")
    int ret = ::accept(fd, addr, &addr_size);
    if (ret == -1) {
      error("获取服务失败1")
    }
    return false;
  }


  bool send(const string &str) {
    int ret = ::send(fd, str.c_str(), str.length(), 0);
    if (ret <= 0) {
      error("发送信息失败!") return false;
    }
    return true;
  }

private:
  addr_t port;       // 端口号
  string ip;         // ip地址
  int fd;            // socket 文件描述符
  sockaddr_in addr_; // 专用socket 地址
  sockaddr *addr;
  socklen_t addr_size; // socket 地址大小

  // 初始化数据
  bool init() {
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
      error("socket 创建失败!") return false;
    }
    addr_.sin_port = htons(port);
    addr_.sin_family = AF_INET;
    if (ip == "any") {
      addr_.sin_addr.s_addr = htonl(INADDR_ANY);
    } else {
      addr_.sin_addr.s_addr = inet_addr(ip.c_str());
      if (addr_.sin_addr.s_addr == INADDR_NONE) {
        error("ip 地址转换错误!")
        return false;
      }
    }
    addr_size = sizeof(addr_);
    addr = (sockaddr *)(&addr_);
    int ret = bind(fd, addr, addr_size);
    if (ret == -1) {
      error("绑定socket 失败!")
      return false;
    }
    return true;
  }
};

int main() {
  Server server;
  server.listen();
  server.accept();
  return 0;
}