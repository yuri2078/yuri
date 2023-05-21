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
    out.join();
    get.join();
  }

  // 连接到服务器 默认本地 2078
  bool connectToServer(addr_t port = 2078, const string &ip = "127.0.0.1") {
    this->port = port;
    this->ip = ip;
    if (init()) {
      int ret = connect(fd, addr, addr_size);
      if (ret == -1) {
        error("连接失败!");
        return false;
      }
    }
    get = std::thread([this]() {
      getMsg(fd);
    });

    out = std::thread([this]() {
      putMsg(fd);
    });

    return true;
  }

  bool send(const string &str) {
    int ret = ::send(fd, str.c_str(), str.length(), 0);
    if (ret <= 0) {
      error("发送信息失败!");
      return false;
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
  std::thread get, out;

  // 初始化数据
  bool init() {
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
      error("socket 创建失败!");
      return false;
    }
    addr_.sin_port = htons(port);
    addr_.sin_family = AF_INET;
    addr_.sin_addr.s_addr = inet_addr(ip.c_str());
    if (addr_.sin_addr.s_addr == INADDR_NONE) {
      error("ip 地址转换错误!");
      return false;
    }
    addr_size = sizeof(addr_);
    addr = (sockaddr *)(&addr_);
    return true;
  }

  void getMsg(int fd) {
    char str[1024];
    while (true) {
      int ret = ::recv(fd, str, 1024, 0);
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
        info("结束与客户端的连接!");
        break;
      }

      ::send(fd, str.c_str(), str.size(), 0);
    }
  }
};

int main() {
  Server client;
  client.connectToServer();
  client.send("yuri is yes");
  return 0;
}
