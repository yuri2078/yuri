# c/c++ socket 网络编程

> 主要基于流 socket(tcp) 有连接，可靠 , 还有一种数据报socket (udp) 无连接，不可靠
> Socket连接是一种用于计算机之间通信的基本方式，它是通过传输层协议（如TCP或UDP）来实现的。

## 基础知识

### 客户端

1. 创建流式socket   -- socket()
2. 向服务器发起连接请求 -- connect()
3. 发送/接收数据 -- send() / recv()
4. 关闭socket连接，释放数据 -- close()

### 服务端

1. 创建流式socket   -- socket()
2. 指定用于通信的ip 和 端口 -- bind()
3. 把socket 设置为监听模式 -- listen()
4. 接受客户端的连接 -- accept()
5. 发送/接收数据 -- send() / recv()
6. 关闭socket连接，释放数据 -- close()

### socket 文件

> 件描述符是Unix和类Unix操作系统中的一个整数值，用于标识打开文件或套接字的引用。它是操作系统对打开文件或套接字的一种抽象表示，可以用于读取、写入或关闭文件或套接字。在Unix和类Unix系统中，所有的文件、套接字和其他I/O设备都被视为文件，每个文件都有一个唯一的文件描述符

在 Unix 系统下，一切设备皆文件, sockert 函数会返回一个文件描述符号

常用文件描述符

+ `0` stdin
+ `1` stdout
+ `2` stderr

## 常用函数

### socket

> 函数原型 `int socket(int domain, int type, int protocol);`

1. `domain` -- 表示协议族或者域，用于指定套接字使用的地址族，例如AF_INET（IPv4）或AF_INET6（IPv6）等
2. `type` -- 表示套接字的类型，指定套接字的传输协议，例如SOCK_STREAM（TCP协议）或SOCK_DGRAM（UDP协议）等
3. `protocol` 表示协议类型，用于在同一地址族中指定协议。通常采用默认值0，表示由domain和type参数确定套接字使用的协议。在有些情况下，如有多个网络协议可供选择的情况下，可以使用protocol参数来指定要使用的协议

综上所述，socket函数的三个参数主要用于指定套接字的地址族、传输协议和协议类型。根据不同的需求和场景，可以灵活地配置这些参数，以创建不同类型的套接字

### bind

> 函数原型 `int bind(int sockfd, struct sockaddr *myaddr, socklen_t addrlen);`

bind()函数用于将一个socket绑定到一个IP地址和端口号。

1. `sockfd`:它的第一个参数是要绑定的socket的描述符
2. `struct sockaddr`:一个指向存有IPv4或IPv6地址、端口号等信息的数据结构（通常是struct sockaddr_in或struct sockaddr_in6类型）
3. `addrlen`:用于存储该数据结构大小的变量

如果bind()函数执行成功，返回值为0，否则返回-1。在这段代码中如果bind()返回值不为0，说明绑定失败，那么就输出一个错误信息，然后关闭socket，函数返回-1。

### accept

> 函数原型 `int accept(int fd, struct sockaddr *__restrict addr,socklen_t *__restrict addr_len);`

accept()函数用于从一个监听socket中接收连接请求，创建一个新的socket用于与客户端通信

1. `fd`:要接受连接的监听socket的描述符
2. `addr`:一个指向存有客户端的IP地址、端口号等信息的数据结构（通常是struct sockaddr_in或struct sockaddr_in6类型）
3. `addr_len`:用于存储该数据结构大小的变量

如果accept()函数执行成功，返回值为新创建的用于与客户端通信的socket的描述符，即clientfd，否则返回-1。在这段代码中如果accept()返回值不为-1，说明成功接受了客户端连接，那么就可以使用clientfd来与客户端进行通信，否则表示接受连接失败。

### inet_ntoa

> 函数原型 `char *inet_ntoa(struct in_addr in);`

inet_ntoa()函数用于将一个存储在struct in_addr类型的变量中的IPv4地址转换成点分十进制的字符串表示。它的参数是一个指向struct in_addr类型变量的指针。

如果inet_ntoa()函数执行成功，返回一个指向转换后的点分十进制字符串的指针，否则返回NULL。

### recv

> 函数原型 `ssize_t recv(int fd, void *buf, size_t n, int flags);`

recv()函数用于从一个已连接的socket接收数据

1. `fd`:目标socket的描述符
2. `buf`:指向存储接收数据的缓冲区的指针
3. `n`:缓冲区的大小
4. `flags`:一组标志，用于控制接收操作的方式 0是一个控制标志，表示以默认方式进行接收操作

如果recv()函数执行成功，返回值为实际接收到的数据的字节数，否则返回-1。如果返回值为0，表示对方已经关闭了连接。

### send

`send()` 函数是 C++ 和 C 系统编程中用于发送数据的函数，通常用于网络编程中，可以向指定的 socket 发送数据。
其函数原型如下：

```c++
#include <sys/socket.h>

ssize_t send(int sockfd, const void *buf, size_t len, int flags);
```

函数参数说明：

+ `sockfd`：指定连接或套接字的文件描述符.

+ `buf`：需要发送的数据的指针。
+ `len`：需要发送的数据的长度。

+ `flags`：指定发送操作的各种控制选项，通常设置为 0。

函数返回值：

+ 如果成功，返回已发送的字节数。

+ 如果失败，返回 -1，并设置 `errno` 变量来指示错误的原因。

使用 `send()` 函数时，需要注意以下几点：

+ 可以将任何数据类型的指针作为 `buf` 参数传递，但通常使用 `char*` 类型的指针来发送文本数据

+ 可以使用 `write()` 函数来替代 `send()` 函数，但有一些区别，例如，`write()` 函数没有支持发送特定标志的选项。

+ `send()` 函数通常用于将数据发送到套接字（socket）中，因此需要先建立连接（如 TCP 的三次握手）和绑定地址。
以上是send函数的详细解析

### gethostbyname

> 根据指定的主机名获取该主机的IP地址信息，涉及到了网络编程中的域名解析

ethostbyname()函数是一个用于获取主机信息的函数，它的参数是主机名字符串，返回值是一个指向hostent结构体的指针，其中包含了主机相关的各种信息，如IP地址、别名等.

函数返回hostent结构体指针，供后续操作使用，例如获取主机的IP地址。

### connect

> 函数原型 `int connect(int fd, const struct sockaddr *addr, socklen_t len);`

+ `sockfd`：套接字文件描述符，即调用socket函数返回的文件描述符；

+ `addr`：包含有目的服务器IP地址和端口号的结构体指针；
+ `addrlen`：addr结构体的大小。

成功：返回0；
失败：返回-1，并设置errno变量.

函数功能：建立与远程服务器的TCP连接，向指定的目的地址发送TCP连接请求。

函数描述： connect函数用于在TCP/IP网络中建立与远程服务器的连接。在客户端执行这个函数之前，需要先创建一个套接字文件描述符，用于发送请求和接收服务器的响应

## 常用数据

### struct sockaddr_in

> 是一个IPv4套接字地址结构体，其中包含了网络通信中的必要信息，例如IP地址、端口号等。

1. `sin_family`：表示地址族，通常为AF_INET。
2. `sin_port`：表示端口号，以网络字节序（Big-Endian）存储。
3. `sin_addr`：表示IP地址，以网络字节序存储。
4. `sin_zero`：填充字段，保证sockaddr_in结构体和sockaddr结构体在长度上的兼容性。

在网络编程中，当客户端需要连接到一个服务器时，需要指定服务器的IP地址和端口号。而struct sockaddr_in结构体就是用来存储这些信息的。通常情况下，开发人员会将服务器地址和端口信息存储在一个名为servaddr的sockaddr_in结构体中，然后将其作为套接字函数的参数，以便建立客户端和服务器之间的连接
