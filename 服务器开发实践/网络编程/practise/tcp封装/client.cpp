#include <sys/socket.h>
#include <yuri.h>

class Client {
  using sockaddr_in = struct sockaddr_in;
  using addr_t = unsigned short int;
  using string = std::string;

public:
  Client() = default;
  ~Client() = default;

  // 连接到服务器 默认本地 2078
  bool connectToServer(addr_t port = 2078, const string &ip = "127.0.0.1") {
    this->port = port;
    this->ip = ip;
    if (init()) {
      int ret = connect(fd, addr, addr_size);
      if (ret == -1) {
        error("连接失败!")
        return false;
      }
    }
    
    return true;
  }

  bool send(const string &str) {
    int ret = ::send(fd, str.c_str(), str.length(), 0);
    if (ret <= 0) {
      error("发送信息失败!")
      return false;
    }
    return true;
  }
private:
  addr_t port; // 端口号
  string ip;     // ip地址
  int fd;        // socket 文件描述符
  sockaddr_in addr_; // 专用socket 地址
  sockaddr *addr;
  socklen_t addr_size; // socket 地址大小

  // 初始化数据
  bool init() {
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
      error("socket 创建失败!")
      return false;
    }
    addr_.sin_port = htons(port);
    addr_.sin_family = AF_INET;
    addr_.sin_addr.s_addr = inet_addr(ip.c_str());
    if (addr_.sin_addr.s_addr == INADDR_NONE) {
      error("ip 地址转换错误!")
      return false;
    }
    addr_size = sizeof(addr_);
    addr = (sockaddr *)(&addr_);
    return true;
  }

};

int main() {
  Client client;
  client.connectToServer();
  client.send("yuri is yes");
  return 0;
}
