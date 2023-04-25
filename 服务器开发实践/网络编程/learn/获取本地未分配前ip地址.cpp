#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <yuri.h>
#include <sys/socket.h>

using Aerror = yuri::Aerror;
using sockaddr_in = struct sockaddr_in;

void showIp(const sockaddr_in &addr) {
  std::cout << "port -> " << htons(addr.sin_port) << std::endl;
  std::cout << "ip  -> " << inet_ntoa(addr.sin_addr) << std::endl;
  
}


int main() {
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  sockaddr_in addr{}, prev;
  showIp(addr);

  // 添加数据
  addr.sin_family = AF_INET;
  addr.sin_port = htons(2078);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  // 为本地socket 分配ip
  if (bind(fd, (struct sockaddr *)(&addr), sizeof(addr)) == -1) {
    error("分配错误!")
  }

  int size = sizeof prev;
  // 获取本地socket 地址
  getsockname(fd, (struct sockaddr *)(&prev), (socklen_t *)&size);
  // 获取通信端socket 地址
  // getpeername(fd, (struct sockaddr *)(&prev), (socklen_t *)&size);
  showIp(prev);
  close(fd);
  return 0;
}


