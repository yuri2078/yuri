// TCP报文头部通常包括以下字段：

// 源端口号：发送端口号
// 目的端口号：接收端口号
// 序列号：用于标识发送的数据包的序号，保证数据包的有序性
// 确认号：用于确认接收端已经收到的数据包序号
// 数据偏移量：表示TCP头部长度，用于指示TCP头部结束位置和数据开始位置
// 保留位：保留未来使用的位
// 标志位：用于控制TCP连接的建立、维护和关闭，包括URG、ACK、PSH、RST、SYN和FIN等标志位
// 窗口大小：用于指示接收端还能接收多少数据，以及发送端应该发送多少数据
// 校验和：用于检验TCP头部和数据的完整性
// 紧急指针：用于指示紧急数据的结束位置，只有在URG标志位被设置时才有效
// 选项字段：包含一些可选的TCP协议扩展字段，如时间戳、窗口扩大因子等。

// tcp 头定义共20字节
#include <cstdint>

int cstdint = INT16_MAX;
  
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
