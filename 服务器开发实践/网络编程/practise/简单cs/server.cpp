#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <yuri.h>
#include <sys/socket.h>

int main() {
  // 创建本地监听 socket
  int listend = socket(AF_INET, SOCK_STREAM, 0);
  if (listend == -1) {
    error("创建socket 失败!")
  }

  // 创建addr
  struct sockaddr_in addr {};
  addr.sin_family = AF_INET;
  addr.sin_port = htons(2078);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);

  // 绑定ip地址
  if (bind(listend, (struct sockaddr *)(&addr), sizeof(addr)) == -1) {
    error("bind 绑定失败!")
  }

  if (listen(listend, 5)) {
    error("设置监听模式失败!")
  }

  struct sockaddr_in serv {};
  socklen_t size = sizeof(serv);
  info("开始获取服务!") int serverd = accept(listend, (struct sockaddr *)(&serv), &size);
  if (serverd == -1) {
    error("获取服务失败!")
  }
  char str[1024];

  if (recv(serverd, str, 1024, 0) <= 0) {
    error("获取信息失败!")
  } else {
    info(str);
  }


  if (send(serverd, std::string("收到你的信息啦!").c_str(), 1024, 0) <= 0) {
    error("获取信息失败!")
  }

  close(listend);
  return 0;
}
