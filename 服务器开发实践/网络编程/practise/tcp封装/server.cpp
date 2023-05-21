#include <sys/socket.h>
#include <thread>
#include <yuri.h>

class Server {
  using sockaddr_in = struct sockaddr_in;
  using addr_t = unsigned short int;
  using string = std::string;

public:
  Server() = default;
  ~Server() {
    thread.join();
  }

  bool accept(addr_t port = 2078, const string &ip = "any", addr_t size = 6) {
    this->port = port;
    this->ip = ip;
    if (init() == false) {
      return false;
    } 
    if (::listen(fd, size) == -1) {
      error("设置监听模式失败!");
    }
    thread = std::thread([this]() {
      server();
    });
    return true;
  }

private:
  addr_t port;       // 端口号
  string ip;         // ip地址
  int fd;            // socket 文件描述符
  sockaddr_in addr_; // 专用socket 地址
  sockaddr *addr;
  socklen_t addr_size; // socket 地址大小
  std::thread thread;

  // 初始化数据
  bool init() {
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
      error("socket 创建失败!");
      return false;
    }
    addr_.sin_port = htons(port);
    addr_.sin_family = AF_INET;
    if (ip == "any") {
      addr_.sin_addr.s_addr = htonl(INADDR_ANY);
    } else {
      addr_.sin_addr.s_addr = inet_addr(ip.c_str());
      if (addr_.sin_addr.s_addr == INADDR_NONE) {
        error("ip 地址转换错误!");
        return false;
      }
    }
    addr_size = sizeof(addr_);
    addr = (sockaddr *)(&addr_);
    int ret = bind(fd, addr, addr_size);
    if (ret == -1) {
      error("绑定socket 失败!");
      return false;
    }
    return true;
  }

  void server() {
    info("开始获取用户");
    while (true) {
      std::thread thread;
      sockaddr_in addr{};
      socklen_t size = sizeof(addr);
      int client = ::accept(fd, reinterpret_cast<sockaddr *>(&addr), &size);
      if (client == -1) {
        error("获取服务失败!");
      }

      std::printf("port -> %d, addres -> %s\n", addr.sin_port, inet_ntoa(addr.sin_addr));
      thread = std::thread([this, client]() {
        getMsg(client);
      });
      std::thread out = std::thread([this, client]() {
        putMsg(client);
      });
      out.detach();
      thread.detach();
    }
  }

  void getMsg(int fd) {
    char str[1024];
    while (true) {
      int ret = recv(fd, str, 1024, 0);
      if (ret <= 0) {
        info("用户断开连接!");
        break;
      }
      str[ret] = 0;
      info(str);
    }
  }

  void putMsg(int fd) {
    std::string str;
    while (true) {
      std::cin >> str;
      if (str == "bye") {
        break;
      }

      send(fd, str.c_str(), str.size(), 0);
    }
  }
};

int main() {
  Server server;
  server.accept();
  return 0;
}
