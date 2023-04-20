#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

int socket(int domain, int type, int protocol);
// 成功时返回文件描述符，失败时返回-1

int bind(int sockfd, struct sockaddr *myaddr, socklen_t addrlen);
// 成功时返回0，失败时返回-1

int accept(int fd, struct sockaddr *__restrict addr, socklen_t *__restrict addr_len);
// 如果接受连接成功，返回一个新的socket的描述符，否则返回-1

char *inet_ntoa(struct in_addr in);
// 函数执行成功，返回一个指向转换后的点分十进制字符串的指针，否则返回NULL

ssize_t recv(int fd, void *buf, size_t n, int flags);
// 如果recv()函数执行成功，返回值为实际接收到的数据的字节数，否则返回-1。如果返回值为0，表示对方已经关闭了连接

ssize_t send(int fd, const void *buf, size_t n, int flags);
// 如果send()函数执行成功，返回值为实际发送的数据的字节数，否则返回-1

int connect(int fd, const struct sockaddr *addr, socklen_t len);

// 通用socker结构体
struct sockaddr;
struct sockaddr_in;
// inet_pton(int af, const char *__restrict cp, void *__restrict buf)