# linux 服务器开发实践

> 读书笔记 《linux c/c++ 服务器开发实践》

## tcp协议

> tcp协议是有连接的可靠的(数据无丢失，数据无失序， 数据无错误， 数据无重复到到) 的传输层系协议，他提供一对一的面向连接的可靠服务

### TCP 的特点

+ 面向连接：在数据传输之前需要建立一个连接，传输完成后需要断开连接。
+ 可靠性：通过序列号、确认号和校验和等机制，保证数据的可靠传输。
+ 流量控制：通过滑动窗口机制，控制数据发送的速度，防止数据的发送方过度发送。
+ 拥塞控制：通过拥塞窗口、超时重传等机制，控制数据在网络中的流量，保证网络的可靠性和稳定性。
+ 面向字节流：将数据视为一个连续的字节流，而不是独立的数据包。
+ 可靠传输：保证数据按照正确的顺序到达接收方，如果数据丢失或损坏，则会自动重传。

### TCP 的连接建立

TCP 的连接建立使用了三次握手（Three-Way Handshake）的机制，具体过程如下：

1. 客户端向服务器发送 SYN 报文，表示请求建立连接。
2. 服务器收到 SYN 报文后，向客户端发送 SYN+ACK 报文，表示确认客户端的请求，并要求建立连接。
3. 客户端收到 SYN+ACK 报文后，向服务器发送 ACK 报文，表示确认服务器的请求，并建立连接。

TCP 的连接终止

TCP 的连接终止使用了四次挥手（Four-Way Handshake）的机制，具体过程如下：

1. 客户端向服务器发送 FIN 报文，表示请求断开连接。
2. 服务器收到 FIN 报文后，向客户端发送 ACK 报文，表示确认客户端的请求。
3. 服务器向客户端发送 FIN 报文，表示服务器也要断开连接。
4. 客户端收到 FIN 报文后，向服务器发送 ACK 报文，表示确认服务器的请求，并断开连接。

TCP 的拥塞控制

TCP 的拥塞控制主要包括拥塞窗口和慢启动两种机制。拥塞窗口是指网络中的可用带宽大小，它是一个动态调整的值，根据网络情况进行自适应调整。慢启动是指在连接建立时，发送方会逐步增加发送数据的速率，直到拥塞窗口达到一个合适的值为止。

TCP 的重传机制
TCP 通过序列号和确认号机制保证数据的

### 报文头

TCP报文头部通常包括以下字段：

+ 源端口号：发送端口号
+ 目的端口号：接收端口号
+ 序列号：用于标识发送的数据包的序号，保证数据包的有序性
+ 确认号：用于确认接收端已经收到的数据包序号
+ 数据偏移量：表示TCP头部长度，用于指示TCP头部结束位置和数据开始位置
+ 保留位：保留未来使用的位
+ 标志位：用于控制TCP连接的建立、维护和关闭，包括URG、ACK、PSH、RST、SYN和FIN等标志位
+ 窗口大小：用于指示接收端还能接收多少数据，以及发送端应该发送多少数据
+ 校验和：用于检验TCP头部和数据的完整性
+ 紧急指针：用于指示紧急数据的结束位置，只有在URG标志位被设置时才有效
+ 选项字段：包含一些可选的TCP协议扩展字段，如时间戳、窗口扩大因子等。

```cpp
typedef struct _TCP_HEADER {
    uint16_t source_port;    // 源端口号 16位
    uint16_t dest_port;      // 目的端口号 16位
    uint32_t seq_num;        // 序列号 32位
    uint32_t ack_num;        // 确认号 32位
    uint16_t hdr_len:4;      // 数据偏移量，占4位
    uint16_t reserved:6;     // 保留位，占6位
    uint16_t flags:6;        // 标志位，占6位
    uint16_t window_size;    // 窗口大小  16位
    uint16_t checksum;       // 校验和 16位
    uint16_t urgent_ptr;     // 紧急指针 16位
    // 选项字段
} TCP_HEADER;
```

## udp协议

> UDP（User Datagram Protocol）是一种无连接的、不可靠的网络传输协议，它没有像TCP那样的确认机制和重发机制，因此传输速度较快，但可靠性较差。他提供一对一或者一对多的，无连接的不可靠通信服务。

UDP报文头主要包括以下字段：

+ 源端口号（Source Port）：发送端口号。
+ 目的端口号（Destination Port）：接收端口号。
+ 长度（Length）：UDP报文长度，包括头部和数据部分。
+ 校验和（Checksum）：用于检验UDP报文的完整性。

```cpp
struct udp_header {
  uint16_t source_port;    // 源端口号
  uint16_t dest_port;      // 目的端口号
  uint16_t length;         // UDP报文长度
  uint16_t checksum;       // 校验和
};
```

其中，source_port和dest_port字段分别用于存储源端口号和目的端口号，长度字段表示UDP报文的长度，checksum字段用于存储校验和。需要注意的是，由于UDP报文头不包含序列号和确认号等信息，因此其长度比TCP报文头要短

## ip协议

> IP数据报是互联网协议 (IP) 中的一种数据传输格式。它是在传输层（如TCP、UDP）之前的网络层中使用的，其中IP是这一层的核心协议。。

### IP数据报的基本结构

IP数据报的基本结构由报头和数据两部分组成：

+ 版本号指的是使用的IP协议版本
+ 头部长度是头部的字节数，最长为60个字节
+ 服务类型用于指定数据包的优先级和特殊需求
+ 总长度则表示整个数据包的长度
+ 标识符和分片偏移用于确定数据包分片后重组的顺序
+ 时限用于控制数据包在网络中的生存时间
+ 协议字段指示了数据包的上层协议，如TCP、UDP等
+ 头校验和用于确认IP数据包的头部是否有错误
+ 源IP地址和目标IP地址则指示了数据包的来源与目的地。

```cpp
struct IPHeader
{
    uint8_t  versionAndHeaderLength;  // 版本和头长度
    uint8_t  typeOfService;           // 服务类型
    uint16_t totalLength;             // 总长度
    uint16_t packetID;                // 分片标识
    uint16_t fragmentOffset;          // 分片偏移
    uint8_t  timeToLive;              // 生存期
    uint8_t  protocol;                // 上层协议
    uint16_t checksum;                // 首部校验和
    uint32_t sourceIP;                // 源IP地址
    uint32_t destIP;                  // 目标IP地址
    // 从这里开始是可选字段（选项）
    // 注意：IP选项不总是出现在结构体中
    uint32_t option1;
    uint32_t option2;
    // ...
    uint32_t optionN;
    // 数据字段
    uint8_t data[0];                  // 可变长数据内容
};
```

### IP数据报的分片

IP数据报的长度通常受到链路层的最大传输单元的限制，因此可能需要在传输过程中进行分片。当IP数据报太大无法通过某个网络时，它会被分成较小的片段，每个片段都会正常地进行传输，最终到达目的地后再恢复为完整数据包。

### IP数据报的选项

IP数据报的选项是可变部分，它允许发送方指定一些控制信息，这些信息超出了标准头部结构的限制。选项字段的长度可以从0到40字节。选项字符集以1个平衡的方式在字节的8个位中传输，以确保没有任何字节会全部为0或1。

### IP地址

IP数据报指定了两个IP地址，一个是源地址，另一个是目标地址。IP地址通常由四个十进制数字组成，每个数字之间用点分隔。IP地址的长度为32位。

传输控制协议 (TCP) 和用户数据报协议 (UDP)
传输控制协议 (TCP) 和用户数据报协议 (UDP) 是两种常见的传输层协议。它们在网络层之上，作为上层协议使用。TCP提供了对数据流的可靠传输，而UDP则提供了非可靠的传输。

### 结论

IP数据报是网络层协议中最为重要的协议之一。通过正确理解IP数据报的基本结构、分片、选项、IP地址和上层协议TCP和UDP，可以更好地理解网络在传输数据过程中的工作原理。

## ARP 协议

> ARP是地址解析协议（Address Resolution Protocol）的缩写，它是一种用于将IP地址解析成物理地址（如MAC地址）的协议。当主机需要发送数据包时，将需要目标主机的IP地址，通过ARP协议获取到目标主机的MAC地址，才能最终将数据包发送到目标主机

ARP报文是一种以太网上的广播消息，用于寻找特定IP地址的MAC地址。ARP报文由以下几部分组成：

+ 硬件类型：表示所使用的硬件类型，如以太网、无线局域网等；
+ 协议类型：表示所使用的网络协议类型，如IP地址；
+ 硬件地址长度：表示硬件地址的长度，通常为6个字节，即MAC地址的长度；
+ 协议地址长度：表示协议地址的长度，通常为4个字节，即IPv4地址的长度；
+ 操作码：请求或者应答，用于标识ARP报文的类型；
+ 发送方MAC地址：发送方硬件地址，即发送方的MAC地址；
+ 发送方IP地址：发送方协议地址，即发送方的IP地址；
+ 目标MAC地址：目标硬件地址，即目标的MAC地址；
+ 目标IP地址：目标协议地址，即目标的IP地址。

```cpp
struct ARPHeader {
    uint16_t hardwareType;  // 硬件类型
    uint16_t protocolType;  // 协议类型
    uint8_t  hardwareSize;  // 硬件地址长度
    uint8_t  protocolSize;  // 协议地址长度
    uint16_t opcode;        // 操作码
    uint8_t  senderMAC[6];  // 发送方MAC地址
    uint32_t senderIP;      // 发送方IP地址
    uint8_t  targetMAC[6];  // 目标MAC地址
    uint32_t targetIP;      // 目标IP地址
};
```

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
