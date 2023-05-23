#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <yuri.h>
#include <sys/socket.h>

int main() {
  // 创建本地socket
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  // 创建addr
  struct sockaddr_in addr{};
  addr.sin_family = AF_INET;
  addr.sin_port = htons(2078);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  info("开始连接服务端!");
  if (connect(fd, (struct sockaddr *)(&addr), sizeof(addr)) == -1) {
    error("连接失败!");
  };

  // sleep(2);
  char str[1024] {};

  send(fd, "你好捏!", 100, 0);
  // recv(fd, str, 1024, 0);
  // info(str);
  sleep(4);
  close(fd);
  return 0;
}
