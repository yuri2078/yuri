#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <iostream>
#include <string>
#include <unistd.h>

#define error(str) \
    std::cout << "\e[31merror! -> " << str << "\e[0m\n";

#define info(str) \
    std::cout << "info -> " << str << "\n";


int main(int argc, char **argv) {
  if (argc != 2) {
    error("需要指定服务端口!")
    return -1;
  }

// 第1步：创建服务端的socket。
  int listenfd = socket(AF_INET, SOCK_STREAM, 0);
  // AF_INET 使用ipv4 协议族 AF_INET6 ipv6
  // SOCK_STREAM类型的传输协议(TCP)
  // 指定了协议号0

  if (listenfd == -1) {
    error("socket流创建失败!")
    return -1;
  }

// 第2步：把服务端用于通信的地址和端口绑定到socket上。
  struct sockaddr_in servaddr; // 服务端地址信息的数据结构。
  memset(&servaddr, 0, sizeof servaddr); // 对servaddr填充 0
  servaddr.sin_family = AF_INET; // 设置协议族， socket 中只能是 AF_INET

  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  // htonl 将主机32未无符号字节序 转换成 32位无符号字节序 / 反之相反
  // INADDR_ANY 监听所有ip地址
  // servaddr.sin_addr.s_addr 服务器要监听的网络字节序

  servaddr.sin_port = htons(std::stoi(argv[1])); // 指定通信端口
  if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) {
    error("bind 错误")
    return -1;
  }

// 第3步：把socket设置为监听模式。
  if (listen(listenfd, 5)) {
    error("设置监听模式错误!")
    close(listenfd);
  }

// 第4步：接受客户端的连接。
  int clientfd;
  int socklen = sizeof(struct sockaddr_in);
  struct sockaddr_in clientaddr;
  clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, (socklen_t *)(&socklen));
  if (clientfd == -1) {
    error("client 连接失败!");
  } else {
    std::cout << "客户端 -> " << inet_ntoa(clientaddr.sin_addr) << " 已经连接\n";
  }

// 第5步：与客户端通信，接收客户端发过来的报文后，回复ok

  char buffer[1024];
  std::string str;
  memset(buffer, 0, sizeof(buffer));
  while (true) {
    
    int iret = recv(clientfd, buffer, sizeof(buffer), 0);
    if (iret > 0) {
      str = "我已经接收到信息捏!";
      std::cout << "本次共接收到 -> " << iret << " 字节的数据\n" << buffer << "\n";
    } else if (iret == 0) {
      info("客户端结束连接!")
      str = "你真的要结束连接吗?";
    } else {
      error("返回字节数错误！")
    }


    iret = send(clientfd, str.c_str(), str.size(), 0);
    if (iret != -1) {
      info("发送响应成功!")
    } else {
      error("发送响应失败!")
      return -1;
    }
  }
  
  close(listenfd);
  close(clientfd);
  
  return 0;
}