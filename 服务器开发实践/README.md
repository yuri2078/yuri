# linux 服务器开发实践

> 读书笔记 《linux c/c++ 服务器开发实践》

## 网络编程常用函数

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

### inet_addr

> 函数原型 `inet_addr(const char* cp)`

将一串ip地址字符串转换为 `struct in_addr`

### inet_pton

> 函数是在网络编程中常用的函数之一，它用于将一个点分十进制的 IP 地址字符串转换成一个二进制 IPv4 或 IPv6 地址。该函数的原型如下：

```c
#include <arpa/inet.h>
int inet_pton(int af, const char *src, void *dst);
```

其中，`af` 表示地址族，只能取值 `AF_INET` 或 `AF_INET6`，分别表示 IPv4 和 IPv6；`src` 是表示点分十进制地址的字符串指针；`dst` 是用于存储转换后二进制地址的指针，其类型为 `void *`，实际上可能是 `struct in_addr *` 或 `struct in6_addr *`。

函数返回值为 `1` 表示转换成功，返回值为 `0` 表示地址格式无效，返回值为 `-1` 表示出错。

使用示例如下：

```c
#include <arpa/inet.h>
#include <stdio.h>
#include <netinet/in.h>

int main() {
  const char* ip_str = "192.168.0.1";
  struct in_addr ip4;
  if (inet_pton(AF_INET, ip_str, &ip4) <= 0) {
    printf("Invalid IP address\n");
    return 1;
  }
  printf("IPv4 address: 0x%x\n", ip4.s_addr);

  const char* ip6_str = "2001:0DB8:AC10:FE01:0000:0000:0000:0000";
  struct in6_addr ip6;
  if (inet_pton(AF_INET6, ip6_str, &ip6) <= 0) {
    printf("Invalid IP address\n");
    return 1;
  }
  printf("IPv6 address: ");
  for (int i = 0; i < 16; i++) {
    printf("%02x", ip6.s6_addr[i]);
    if (i % 2 == 1 && i < 15) {
      printf(":");
    }
  }
  printf("\n");
  return 0;
}
```

上述代码中，首先定义一个表示 IPv4 地址的字符串 `ip_str` 和一个表示 IPv6 地址的字符串 `ip6_str`。然后，定义了两个用于存储转换后地址的结构体 `ip4` 和 `ip6`。接着，调用 `inet_pton()` 函数将两个字符串分别转换成二进制的 IPv4 和 IPv6 地址。如果转换失败，则输出错误信息；否则，输出转换后的 IPv4 和 IPv6 地址。

可以看到，在转换 IPv6 地址时，需要使用循环结构遍历 `ip6` 结构体中的 16 个字节，并以 `:` 分割每 2 个字节。

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

### getsockname

> `getsockname` 函数可以用于获取一个已绑定到本地地址的套接字的本地协议地址，它的原型为：

```c
int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```

- `sockfd`：要获取本地协议地址的套接字的描述符；
- `addr`：指向存放返回的本地协议地址的结构体的指针；
- `addrlen`：指向 `sockaddr` 结构体的长度，同时也会更新为实际地址结构体的长度

### getpeername

> `getpeername` 函数可以用于获取一个已连接套接字的远程主机的地址和端口号，它的原型为：

```c
int getpeername(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```

- `sockfd`：要获取远程主机地址和端口号的已连接套接字的描述符；
- `addr`：指向存放返回的远程主机地址的结构体的指针；
- `addrlen`：指向 `sockaddr` 结构体的长度，同时也会更新为实际地址结构体的长度。

### connect

> 函数原型 `int connect(int fd, const struct sockaddr *addr, socklen_t len);`

+ `sockfd`：套接字文件描述符，即调用socket函数返回的文件描述符；

+ `addr`：包含有目的服务器IP地址和端口号的结构体指针；
+ `addrlen`：addr结构体的大小。

成功：返回0；
失败：返回-1，并设置errno变量.

函数功能：建立与远程服务器的TCP连接，向指定的目的地址发送TCP连接请求。

函数描述： connect函数用于在TCP/IP网络中建立与远程服务器的连接。在客户端执行这个函数之前，需要先创建一个套接字文件描述符，用于发送请求和接收服务器的响应

## 常用数据结构

### 字节序

> 字节顺序（Byte Order）也叫 Endianness，是用来表示一个多字节数据类型（比如整数）在内存中存储的顺序方式。在计算机发展的早期，由于不同的计算机采用的处理器架构不同，处理器的字节序也存在差异，因此，数据存储时需要遵循特定的字节序。

目前，通用的字节序有两种：

- 大端字节序（Big-Endian）：低地址存放高位字节，高地址存放低位字节。
- 小端字节序（Little-Endian）：低地址存放低位字节，高地址存放高位字节。

例如，对于一个 2 字节的整数 0x1234，按照大端字节序存储的话，在内存中是这样的：

```sh
0x1000: 12　　高地址
0x1001: 34　　低地址
```

而按照小端字节序存储的话，在内存中则是这样的：

```sh
0x1000: 34　　低地址
0x1001: 12　　高地址
```

在网络编程中，由于不同计算机的字节序可能不同，可能会对数据的传输和解释产生误解。为了解决这个问题，网络通信中一般采用大端字节序（也称为网络字节序）来传输数据，以确保不同主机之间的数据传输正确性。网络字节序采用大端字节序，在数据传输过程中，发送方将数据转换为网络字节序（使用 `htons()` 函数），接收方在接收数据之后再将其转换为本地主机字节序（使用 `ntohs()` 函数）

### sockaddr

> sockaddr 是一个通用的套接字地址结构体，用于表示各种网络协议的地址信息，其定义如下：

```c
struct sockaddr
{
  __SOCKADDR_COMMON (sa_);	// 地址簇
  char sa_data[14];		// 实际地址	
};
```

该结构体中的 `sa_family` 成员指定了地址族类型，常用的地址族包括：

- `AF_INET`：IPv4 地址族
- `AF_INET6`：IPv6 地址族
- `AF_LOCAL`：本地通信地址族
- `AF_PACKET`：底层协议（比如以太网）地址族

不同的地址族需要使用不同的数据类型存储真实的地址信息，因此在 `sockaddr` 结构体中，使用 `sa_data` 数组存储实际的地址信息。实际上，`sa_data` 数组的大小为 14 字节，但不同的地址族只会使用其中一部分，其具体使用情况如下：

| 地址族    | 实际的地址信息                     |
| --------- | ---------------------------------- |
| AF_INET   | 2 字节端口号 + 4 字节 IP 地址      |
| AF_INET6  | 2 字节端口号 + 16 字节 IP 地址     |
| AF_LOCAL  | 最多 108 字节的路径名              |
| AF_PACKET | 14 字节以太网地址 + 4 字节协议类型 |

IPv6 地址需要使用大端序（网络字节序）存储，而 IPv4 地址需要使用小端序存储 

当然，在实际使用中，为了方便，我们一般会使用更具体的地址结构体，如 `struct sockaddr_in`（IPv4）和 `struct sockaddr_in6`（IPv6），它们继承了 `struct sockaddr` 的全部成员，同时还定义了额外的成员，用于存储更具体的地址信息。

### sockaddr_in

> 是一个IPv4套接字地址结构体，其中包含了网络通信中的必要信息，例如IP地址、端口号等。
>
> 使用小端序就行存储

```c++
struct sockaddr_in
{
  __SOCKADDR_COMMON (sin_); // 地址族
  in_port_t sin_port;			// 端口号
  struct in_addr sin_addr;		// 网络地址

  /* 为了和sockaddr 对齐,用于填充的0'.  */
  unsigned char sin_zero[sizeof (struct sockaddr) // 通用套接字大小
                         - __SOCKADDR_COMMON_SIZE // 地址族大小
                         - sizeof (in_port_t) // 端口号大小
                         - sizeof (struct in_addr)]; // 网络地址大小
};

// 存储网络地址
typedef uint32_t in_addr_t;
struct in_addr
{
  in_addr_t s_addr;
};
```



1. `sin_family`：表示地址族，通常为AF_INET。
2. `sin_port`：表示端口号，以网络字节序（Big-Endian）存储。
3. `sin_addr`：表示IP地址，以网络字节序存储。
4. `sin_zero`：填充字段，保证sockaddr_in结构体和sockaddr结构体在长度上的兼容性。

在网络编程中，当客户端需要连接到一个服务器时，需要指定服务器的IP地址和端口号。而struct sockaddr_in结构体就是用来存储这些信息的。通常情况下，开发人员会将服务器地址和端口信息存储在一个名为servaddr的sockaddr_in结构体中，然后将其作为套接字函数的参数，以便建立客户端和服务器之间的连接

## 多线程常用函数

### pthread_create

>：pthread_create() 函数用于创建一个新的线程，并启动执行。它的函数声明如下：

```cpp
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine)(void *), void *arg);
```

函数参数的解析如下：

+ thread：是一个指向 pthread_t 类型的指针，用于保存新线程的 ID。
+ attr：是一个指向 pthread_attr_t 类型的指针，用于设置新线程的属性，可以设置为 NULL 使用默认属性。
+ start_routine：是一个指向函数的指针，用于指定新线程要执行的函数。
+ arg：是一个 void 指针，用于向新线程传递参数，传递的值可以是任意类型的指针。

函数的返回值为

+ 若线程创建成功，则返回 0，并通过 thread 参数返回新线程的 ID。
+ 若线程创建失败，则返回一个非零的错误代码

### pthread_join()：等待一个线程结束并回收其资源

### pthread_mutex_init()和pthread_mutex_destroy()：初始化和销毁互斥锁

### pthread_mutex_lock()和pthread_mutex_unlock()：锁定和释放互斥锁

### pthread_cond_init()和pthread_cond_destroy()：初始化和销毁条件变量

### pthread_cond_wait()和pthread_cond_signal()：阻塞等待条件变量和发送条件信号

### pthread_cancel()：请求取消一个线程

### pthread_exit()：退出当前线程

### pthread_setcancelstate()和pthread_setcanceltype()：设置线程的取消状态和方式

### pthread_attr_init()和pthread_attr_destroy()：初始化和销毁线程属性

### pthread_attr_setdetachstate()：设置线程的分离状态

## 线程的属性

> POSIX 标准规定了用于管控线程行为的线程属性，这些线程属性可以在创建线程时指定或者使用 `pthread_attr_set*` 和 `pthread_attr_get*` 函数进行修改或查询。

下面是 POSIX 标准规定的线程属性：

+ 线程栈大小（Stack Size）
  
  > 局部变量都是在栈上生成的。
  
  可以通过 `pthread_attr_setstacksize()` 函数设置新线程的栈大小。默认值在不同实现中可能不同

  `PTHREAD_STACK_MIN` 获取最小栈大小

  ```cpp
  pthread_attr_getstacksize(&attr, &stack_size); // 获取当前栈大小
  std::cout << "当前栈大小 -> " << stack_size << "  最小栈大小是 -> " << PTHREAD_STACK_MIN << "\n";
  ```
  
+ 线程栈地址（Stack Address）

    可以通过 `pthread_attr_setstack()` 函数设置新线程的栈内存。
  + 如果指定了线程栈地址，那么必须也指定线程栈大小。
  + 如果没有指定线程栈地址，那么新线程的栈内存就由系统分配。

+ 线程调度策略（Scheduling Policy）

  可以通过 `pthread_attr_setschedpolicy()` 函数设置新线程的调度策略。

  + `SCHED_OTHER` 非实时调度 分时调度策略。非实时调度 给每个线程分配时间，前一个不完成，是不会执行后面的线程的。没有优先级之分
  + `SCHED_FIFO` 实时调度 先来服务调度策略。 实时调度 按照线程创建的时间安排顺序，如果有优先级高的先处理优先级高的
  + `SCHED_RR` 实时调度 时间片轮转策略。 非每个线程分配时间片，用完了就自己排到最后重新分配时间片 但是支持优先级抢占

  + 默认调度策略一般为 SCHED_OTHER。

  ```cpp
  std::cout << "SCHED_OTHER"
            << " " << sched_get_priority_min(SCHED_OTHER) << " - "
            << sched_get_priority_max(SCHED_OTHER) << "\n";
  std::cout << "SCHED_FIFO"
            << " " << sched_get_priority_min(SCHED_FIFO) << " - "
            << sched_get_priority_max(SCHED_FIFO) << "\n";
  std::cout << "SCHED_RR"
            << " " << sched_get_priority_min(SCHED_RR) << " - "
            << sched_get_priority_max(SCHED_RR) << "\n\n";
  ```

+ 线程调度优先级（Scheduling Priority）
  
  + 可以通过` pthread_attr_setschedparam() `函数设置线程的调度优先级。
  + 只有在使用实时调度策略时调度优先级才会有意义。
  + 调度优先级有一个范围，通常是 0（最低优先级）到 99（最高优先级）之间。
  + 默认调度优先级一般为 0。

+ 线程继承属性（Inherit Scheduling Attribute）
  
  + 可以通过 `pthread_attr_setinheritsched()` 函数设置新线程是否继承当前线程的调度策略和调度优先级。

  + 当设置为 PTHREAD_INHERIT_SCHED 时，新线程会继承调用 `pthread_create()` 函数的线程的调度属性。

  + 当设置为 PTHREAD_EXPLICIT_SCHED 时，新线程会使用指定的调度属性。

+ 线程分离属性（Detached Attribute）
  
  + 可以通过`pthread_attr_setdetachstate()`函数设置新线程是分离线程还是非分离线程。
  + 分离线程是指执行完自身任务后，线程立即释放分配给它的所有资源，不留下线程描述信息供其他线程查询；非分离线程就是正常线程。
  + `pthread_detach(pthread_self())` 将本线程设置为可分离属性
  + 默认情况下，新线程是非分离线程。

  ```cpp
  pthread_detach(pthread_self()); // 将本线程分离状态属性设置为 可分离属性
  
  pthread_getattr_np(pthread_self(), &attr); // 获取属性
  pthread_attr_getdetachstate(&attr, &detachstate); // 获取属性
  pthread_attr_setdetachstate(&attr, detachstate); // 设置属性
  pthread_attr_destroy(&attr); // 使用 pthread_getattr_np 获取后需要销毁掉不用的attr
  ```

## 线程的退出

退出方式:

1. 主动退出

   1. 函数使用`pthread_exit(void *value)` 函数主动退出
   2. 函数`return` 主动退出

    ```cpp
    void *ptread_fun(void *arg) {
      for (int i = 1; i; i++) {
        std::cout << "i -> " << i << "\n";
        sleep(1);
        if (i == 5) {
          // 主动退出
          pthread_exit(nullptr);
        }
      }
      // 线程主动退出
      return nullptr;
    }
    ```

2. 被动退出

   1. `pthread_kill` 向线程发送信号

      + 第一个参数 `pthread_id` 线程id
      + 第二个参数 发送的信号
      
        + 如果信号不存在，就直接退出线程
        + 如果信号为0,则探测线程是否存在，存在返回-1
        + 如果信号不为0 且，存在则在对应的函数就行处理

      ```cpp
      #include <pthread.h>
      #include <iostream>
      #include <sched.h>
      #include <unistd.h>
      #include <signal.h>
      
      static void on_signal_term(int sig) {
        std::cout << "信号处理函数 sig -> " << sig << "\n";
        pthread_exit(nullptr);
      }
      
      void *ptread_fun(void *arg) {
        // 注册线程
        signal(SIGQUIT, on_signal_term);
        for (int i = 1; i; i++) {
          std::cout << "i -> " << i << "\n";
          sleep(1);
        }
        // 线程主动退出
        return nullptr;
      }


      int main() {
    
        pthread_t *ret = new pthread_t; // 新线程id  unsigned long int
        std::cout << "程序 开始执行\n";
    
        // 创建线程并开始执行，默认创建的是非分离线程，也就是可连接线程
        pthread_create(ret, nullptr, ptread_fun, nullptr);
        sleep(5); // 先休息5s
        int return_val = pthread_kill(*ret, 3);
        // 让主线程等在他执行完毕
        pthread_join(*ret, nullptr);
        std::cout << "return_value -> " << return_val << "\n";
        std::cout << "主线程结束!\n";
        delete ret;
        return 0;
      }
    
      ```

   2. 使用`pthread_cancel`发送可以取消线程的信号

        发送信号之后他不会退出线程，直到遇到 stdin stdout read wirte之类的
        或者检测到了`pthread_testcancel`函数

    ```cpp
    void *ptread_fun(void *arg) {
      std::cout << "子线程开始执行!\n";
      for (int i = 1; i; i++) {
        // std::cout << "i -> " << i << "\n";
        sleep(1);
        pthread_testcancel();
      }
      // 线程主动退出
      return nullptr;
    }
    
    int main() {
      pthread_t *ret = new pthread_t; // 新线程id  unsigned long int
      std::cout << "程序 开始执行\n";
    
      // 创建线程并开始执行，默认创建的是非分离线程，也就是可连接线程
    
      pthread_create(ret, nullptr, ptread_fun, nullptr);
      sleep(5); // 先休息5s
      int return_val = pthread_cancel(*ret);
      pthread_join(*ret, nullptr);
      
      std::cout << "return_value -> " << return_val << "\n";
      std::cout << "主线程结束!\n";
      delete ret;
      return 0;
    }
    ```

## 线程的清理

```cpp
#include <pthread.h>
#include <iostream>
#include <sched.h>
#include <unistd.h>

void clean_fun(void *arg) {
  std::cout << "线程的清理函数调用 -> " << *((int *)arg) << "\n";
}

void *ptread_fun_1(void *arg) {
  std::cout << "线程 (1) 开始运行\n";
  int m = 1;
  pthread_cleanup_push(clean_fun, &m); // 两个配套使用
  return nullptr; // 也会引发清理函数
  pthread_cleanup_pop(0); // 0表示不清理，大于0 表示清理
}

void *ptread_fun_2(void *arg) {
  std::cout << "线程 (2) 开始运行\n";
  int m = 2;
  pthread_cleanup_push(clean_fun, &m);
  // 采用堆栈，将清理函数入栈
  pthread_exit(nullptr); // 会引发清理函数
  pthread_cleanup_pop(0);
}

int main() {

  pthread_t *ret_1 = new pthread_t, *ret_2 = new pthread_t;
  std::cout << "程序 开始执行\n";

  // 创建线程并开始执行，默认创建的是非分离线程，也就是可连接线程
  pthread_create(ret_1, nullptr, ptread_fun_1, nullptr);
  pthread_create(ret_2, nullptr, ptread_fun_2, nullptr);

  // 让主线程等在他执行完毕
  pthread_join(*ret_1, nullptr);
  pthread_join(*ret_2, nullptr);

  std::cout << "主线程结束!\n";
  delete ret_1;
  delete ret_2;
  return 0;
}
```

## 线程同步

> 多线程中经常需要多个线程访问同一个变量，但是因为是多线程运行，所以会出现争抢问题。比如第一个线程将i(0) + 1 后写入寄存器，那么寄存器中的值应该是1 ，当第二个线程这么做时他的结果理应是2,但如果他在i = 0时就读取数据那么他会将1写入寄存器，最后结果仍任是1,下面看个例子

### 列子

```c++
#include <pthread.h>
#include <iostream>

int arg = 0;

void *th_fun(void *) {
  for (int i = 0; i < 100000; i++) {
    arg++;
  }

  return nullptr;
}

void *th_fun2(void *) {
  for (int i = 0; i < 100000; i++) {
    arg++;
  }
  return nullptr;
}

int main() {
  pthread_t th1, th2;
  for (int i = 0; i < 10; i++) {
    pthread_create(&th1, nullptr, th_fun, nullptr);
    pthread_create(&th2, nullptr, th_fun2, nullptr);
    pthread_join(th1, nullptr);
    pthread_join(th2, nullptr);

    std::cout << "arg -> " << arg << std::endl;
    arg = 0;
  }
  
  return 0;
}

// 打印结果 没有一次是正确答案200000
/* 
arg -> 102470
arg -> 103754
arg -> 140057
arg -> 133124
arg -> 105652
arg -> 106397
arg -> 126014
arg -> 127684
arg -> 105871
arg -> 137969
*/
```

### 互斥锁

> 建于上面的问题我们就需要用到互斥锁了.当我们把临界资源锁起来是,别的资源是不能够进行访问的

- `pthread_mutex_init(&mutex, nullptr);` 初始化互斥锁,nullptr表示采用默认属性

- `mutex = PTHREAD_MUTEX_INITIALIZER;` 也可以这样初始化,但是这个只能初始化结构体不能是指针

- `int pthread_mutex_trylock(pthread_mutex_t *mutex);` 尝试上锁,不会阻塞线程,获得不了就返回

- `pthread_mutex_lock(&mutex);` 上锁

- `pthread_mutex_destroy(&mutex);`  使用完毕后需要销毁互斥锁

  ```c++
  #include <pthread.h>
  #include <iostream>
  
  pthread_mutex_t mutex;
  int arg = 0;
  
  void *th_fun(void *) {
    for (int i = 0; i < 100000; i++) {
      pthread_mutex_lock(&mutex);
      arg++;
      pthread_mutex_unlock(&mutex);
    }
  
    return nullptr;
  }
  
  void *th_fun2(void *) {
    for (int i = 0; i < 100000; i++) {
      pthread_mutex_lock(&mutex);
      arg++;
      pthread_mutex_unlock(&mutex);
    }
    return nullptr;
  }
  
  int main() {
    pthread_t th1, th2;
    pthread_mutex_init(&mutex, nullptr); // 初始化互斥锁
    for (int i = 0; i < 10; i++) {
      pthread_create(&th1, nullptr, th_fun, nullptr);
      pthread_create(&th2, nullptr, th_fun2, nullptr);
      pthread_join(th1, nullptr);
      
      std::cout << "arg -> " << arg << std::endl;
      arg = 0;
    }
    pthread_mutex_destroy(&mutex); // 使用完毕后需要销毁互斥锁
    return 0;
  }
  
  // 这时候发现结果都是对的了
  ```

  

### 读写锁

> 有些时候我们只读,不写不会影响别的操作.但是如果用互斥锁会很影响客户体验,因为线程会一直阻塞.使用读写锁就可以解决这个问题.这样可以提高并发性

```c++
#include <pthread.h>

int mian() {
  pthread_rwlock_t mutex; // 新建读写锁
  mutex = PTHREAD_RWLOCK_INITIALIZER; // 初始化读写锁
  pthread_rwlock_init(&mutex, nullptr);

  pthread_rwlock_rdlock(&mutex); // 读模式上锁 会阻塞线程
  pthread_rwlock_tryrdlock(&mutex); // 读模式尝试上锁 不会阻塞线程

  pthread_rwlock_wrlock(&mutex); // 写模式尝试上锁 会阻塞线程
  pthread_rwlock_trywrlock(&mutex); // 写模式尝试上锁 不会阻塞线程

  // 如果读模式上锁 如果锁在别的读模式上,可以直接读取. 如果在写模式上或者将要到写模式上他就会阻塞

  pthread_rwlock_destroy(&mutex); 
  
  return 0;
}
```



## 条件变量

> 线程A 需要某个条件才能继续执行 ,在线程B中达成这个条件后就会唤醒线程A 这就是条件变量



## c++ 11 多线程

### thread 

> 多线程类

#### 默认情况:

1. 默认创建的对象不传函数参数，默认不会执行
2. 默认创建的可连接线程
3. thread::id 线程id

#### 常用函数

- `void join()` 将thread 类的线程等待子线程完成后再退出
- `void detach()` 将thread 类线程改为分离线程
- `thread(thread &&x)` 将x 的线程移动， x的线程将不会执行
- `this_thread::get_id()` 获取本线程的id
- `this_thread::yield()` 让出本线程的CPU时间片(需要循环一直让出)
- `this_thread::sleep_until` 暂停线程直到 -- 时间
- `this_thread::sleep_for` 暂停线程多少时间



### 案例

### this_thread::yield

```c++
#include <pthread.h>
#include <thread>
#include <iostream>

using std::cout;
using std::thread;

bool ready = false;

void thfun(int &&val) {
  while (!ready) {
    std::this_thread::yield(); //让出自己的时间片
  }
  for (int i = 0; i < 1000000; i++) {
    
  }
  cout << val << std::endl;
}

int main() {
  cout << "主线程开始\n";

  thread thread_[10];
  for (int i = 0; i < 10; i++) {
    thread_[i] = thread (thfun, i);
    
  }

  ready = true;
  for (int i = 0; i < 10; i++) {
    thread_[i].join();
  }
  cout << "主线程结束执行\n";
  return 0;
}

// thread test;  直接定义不会执行线程 默认定义的是可连接线程，需要使用join 等待结束
```

