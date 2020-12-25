#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// 文件描述信息
#pragma pack(1)
typedef struct _file_info
{
    char name[51];
    unsigned int size;
} file_info;
#pragma pack()

/* int connect(int sockfd,const struct sockaddr *servaddr socklen_t * addrlen);*/
// 返回：非负描述字 ——成功，-1 ——出错
// TCP 客户用 connect 函数来建立与 TCP 服务器的连接，激发 TCP 的三次握手过程。
// 客户在调用函数 connect 前不必非得调用 bind 函数，因为如果需要的话，内核会确定源 IP 地址，并选择一个临时端口作为源端口。




