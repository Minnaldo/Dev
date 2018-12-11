#include <arpa/inet.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sys/socket.h>

#define MAXLINE 1024

using namespace std;

int main(int argc, char const *argv[])
{
    struct sockaddr_in serveraddr;
    char buf[MAXLINE];
    // * 1번째 인자 - 프로토콜 체계 (PF_INET : IPv4, PF_INET6 : IPv6) 이들은 매크로 상수
    // * 2번째 인자 - 서비스 타입 (SOCK_STREAM : TCP, SOCK_DGRAM : UDP)
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        cerr << "Socket Failed";
        return 1;
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_port = htons(9999);

    socklen_t client_len = sizeof(serveraddr);
    if (connect(sock, (struct sockaddr *)&serveraddr, client_len) == -1)
    {
        cerr << "coonect error" << endl;
        return 1;
    }
    memset(buf, 0x00, MAXLINE); //cstring헤더에 포함 : memset
    recv(sock, buf, MAXLINE, 0);

    if (send(sock, buf, MAXLINE, MSG_NOSIGNAL) <= 0)
    {
        cerr << "write error";
        return 1;
    }
    memset(buf, 0x00, MAXLINE);
    if (recv(sock, buf, MAXLINE, 0) <= 0)
    {
        perror("read error");
        return 1;
    }

    shutdown(sock, SHUT_RDWR);

    cout << "server : " << buf << endl;
    return 0;
}