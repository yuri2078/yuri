#include <algorithm>
#include <sys/socket.h>
#include <vector>
#include <yuri.h>

class Client {
  using sockaddr_in = struct sockaddr_in;
  using addr_t = unsigned short int;
  using string = std::string;

public:
  Client() = default;
  ~Client() = default;

  bool operator<(Client &a) {
    return false;
  }

  bool compare(int x, int y) {
    return false;
  }

  // 连接到服务器 默认本地 2078
  bool connectToServer(addr_t port = 2078, const string &ip = "127.0.0.1") {
    this->port = port;
    this->ip = ip;
    if (init()) {
      int ret = connect(fd, addr, addr_size);
    }
    
    return false;
  }

  
private:
  addr_t port; // 端口号
  addr_t family; // 协议族
  string ip;     // ip地址
  int fd;        // socket 文件描述符
  sockaddr_in addr_; // 专用socket 地址
  sockaddr *addr;
  socklen_t addr_size; // socket 地址大小

  bool init() {
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
      error("socket 创建失败!")
      return false;
    }

    addr_.sin_port = htons(port);
    addr_.sin_family = family;
    addr_.sin_addr.s_addr = inet_addr(ip.c_str());
    if (addr_.sin_addr.s_addr == INADDR_NONE) {
      error("ip 地址转换错误!")
      return false;
    }
    addr = (sockaddr *)(&addr_);
    return true;
  }
};

template <typename T>
void add(T x, T y) {
}

void test() {
  std::vector<int> c;
  std::sort(c.begin(), c.end(), [](Client a) {
     if(a.compare(1, 2) == 0){
        add<double>(1.1,2);
     }
  });
}