#include "tcp_client.h"

int main(int argc, char const *argv)
{
    file_info fi;
    char buf[1024];
    // 创建套接字
    int sock;
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // 连接服务器
    // 指定服务器地址
    struct sockaddr_in srvaddr;
    srvaddr.sin_family = AF_INET;
    srvaddr.sin_addr.s_addr = inet_addr(argv[1]);
    srvaddr.sin_port = htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr*)&srvaddr, sizeof(srvaddr)) == -1){
        perror("connect error");
        exit(1);
    }

    // 收发数据

    int reg;
    FILE* fp = NULL;

    reg = recv(sock, &fi, sizeof(fi), 0);
    if(reg < sizeof(fi)){
        printf("接收错误\n");
        exit(1);
    }
    printf("%d\n",fi.size);
    fp = fopen(fi.name, "wb");
    if(fp == NULL){
        perror("打开文件失败\n");
        exit(1);
    }
    printf("%d\n",fi.size);
    fp = fopen(fi.name, "wb");
    if(fp == NULL){
        perror("打开文件失败\n");
        exit(1);
    }
    while(1){
        reg = recv(sock, buf, sizeof(buf), 0);
        if(reg == 0){
            break;
        }
        fwrite(buf, 1, reg, fp);
    }

    // 断开连接(关闭套接字)

}