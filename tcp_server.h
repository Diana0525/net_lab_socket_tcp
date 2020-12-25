#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
/* int socket(int family,int type,int protocol); */
// 返回：非负描述字 ——成功，-1 ——出错
// 其中 family 参数指明协议栈（family),该参数也往往被称为协议域（domain）
// type 参数指明套接口类型
// protocol 参数应设计为某个协议类型常值，或者设为0，以选择所给定 family 和 type 组合的系统缺省值。

/* int bind(int sockfd,const struct sockaddr * myaddr,socklen_t addrlen); */
// bind 函数把一个本地协议地址赋予一个套接口
// 协议地址是指 32 位的 IPv4 地址与 16 位的 TCP/UDP 端口号的组合。

/* int listen(int sockfd,int backlog); */
// listen 函数仅由 TCP 服务器调用，做两件事情：
// 当socket函数创建一个套接口时，它被假设为一个主动套接口，也就是说，它是一个将调用connect发起连接的客户套接口。listen函数把一个未连接的套接口转换成一个被动套接口，指示内核应接受指向该套接口的连接请求。
// 本函数的第二个参数规定了内核应该为相应套接口排队的最大连接个数

/* int accept(int sockfd,struct sockaddr *cliaddr, socklen_t * addrlen); */
// accept 函数由 TCP 服务器调用，用于从已完成连接队列队头返回下一个已完成连接。如果已完成连接队列为空，那么进程被投入睡眠（假定套接口为确实的阻塞方式）。

// 文件描述信息
#pragma pack(1)
typedef struct _file_info
{
    char name[51];
    unsigned int size;
} file_info;
#pragma pack()