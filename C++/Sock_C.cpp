#include <arpa/inet.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sys/socket.h>

#define MAXLINE 1024

/** * the source code that cs style network
 *  * Client
 *  * LoopBack IP
 */

using namespace std;

int main(int argc, char const *argv[])
{
    struct sockaddr_in server_addr;
    char buf[MAXLINE];
    // * 1번째 인자 - 프로토콜 체계 (PF_INET : IPv4, PF_INET6 : IPv6) 이들은 매크로 상수
    // * 2번째 인자 - 서비스 타입 (SOCK_STREAM : TCP, SOCK_DGRAM : UDP)
    int client_socket = socket(PF_INET, SOCK_STREAM, 0); //클라이언트 소켓 설정
    if (client_socket == -1)
    {
        cerr << "Socket Failed\n";
        return 1;
    }

    server_addr.sin_family = AF_INET;                     // 프로토콜 방식
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //접속할 서버의 주소 설정
    server_addr.sin_port = htons(9999);                   //접속할 서버의 포트번호

    socklen_t client_len = sizeof(server_addr);

    if (connect(client_socket, (struct sockaddr *)&server_addr, client_len) == -1)
    {
        cerr << "coonect error\n";
        return 1;
    }
    memset(buf, 0x00, MAXLINE); //cstring헤더에 포함 : memset

    //여기부터 while문을 통해 반복되게 만든다, 종료 조건은?
    while (true)
    {
        if (send(client_socket, buf, MAXLINE, MSG_NOSIGNAL) <= 0)
        {
            cerr << "write error\n";
            return 1;
        }

        if (recv(client_socket, buf, MAXLINE, 0) <= 0)
        {
            cerr << "read error\n";
            return 1;
        }

        cout << "server : " << buf << endl;
        memset(buf, 0x00, MAXLINE); // 입력 버퍼 초기화
    }
    shutdown(client_socket, SHUT_RDWR);
    return 0;
}