#include <arpa/inet.h>
#include <netdb.h>
#include <sstream>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <yuri.h>
    
int main(int argc, char **argv) {
  if (argc != 3) {
    error("请指定ip 地址和端口号!\n");
    return -1;
  }

// 第1步：创建客户端的socket。
  int sockfd;
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    error("创建socket 失败！")
    return -1;
  }

// 第2步：向服务器发起连接请求。
  struct hostent *h;
//   函数返回hostent结构体指针，供后续操作使用，例如获取主机的IP地址。
  if ((h = gethostbyname(argv[1])) == 0)
  // 指定服务端的ip地址。 根据ip地址获取主机名
  {
    error("主机名获取 失败!\n");
    close(sockfd);
    return -1;
  }

  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  // 指定服务端的通信端口。 将网络字节流转换成本地字节流
  memcpy(&servaddr.sin_addr, h->h_addr, h->h_length);
  // 将指定长度的数据拷贝进去memcpy()函数用于从源地址复制指定长度的数据到目标地址中。
  //   在此代码中，它的作用是将主机名解析得到的IP地址信息复制到目标地址中，以便于后续网络通信使用
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) // 向服务端发起连接清求。
  {
    error("连接失败！");
    close(sockfd);
    return -1;
  } else {
    info("连接成功\n")
  }

  char buffer[1024]{};

  // 第3步：与服务端通信，发送一个报文后等待回复，然后再发下一个报文。
  for (int i = 0; i < 10; i++) {
    std::stringstream str;
    str << "这是第 -> " << i + 1 << " 条信息";
    int iret = send(sockfd, str.str().c_str(), str.str().size(), 0);
    if (iret == -1) {
      error("发送失败")
      return -1;
    } else {
      info("发送成功 -- ")
      std::cout << str.str() << std::endl;
    }
    iret = recv(sockfd, buffer, sizeof(buffer), 0);

    if (iret > 0) {
      std::cout << "本次共接收到 -> " << iret << " 字节的数据\n" << buffer << "\n";
    } else if (iret == 0) {
      info("客户端结束连接!")
    } else {
      error("返回字节数错误！")
    }
    sleep(1);
  }

  // 第4步：关闭socket，释放资源
  close(sockfd);
}
