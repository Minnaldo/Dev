/**
 *  ! 문제 발생 bind 에서
 */

#include <arpa/inet.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sys/socket.h>

#define MAXLINE 1024

using namespace std;

int main(int argc, char const *argv[])
{
    int server_socket;
    int client_socket;

    struct sockaddr_in serveraddr;
    struct sockaddr_in client_addr;

    char buf_rcv[MAXLINE + 5];
    char buf_snd[MAXLINE + 5];

    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (-1 == server_socket)
    {
        cerr << "server socket 생성 실패" << endl;
        exit(1);
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(9999);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (-1 == bind(server_socket, (struct sockaddr *)&serveraddr, sizeof(serveraddr)))
    {
        cerr << "bind() 실행 에러" << endl;
        exit(1);
    }

    while (1)
    {
        if (-1 == listen(server_socket, 5))
        {
            cerr << "대기상태 모드 설정 실패" << endl;
            exit(1);
        }

        socklen_t client_addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);

        if (-1 == client_socket)
        {
            cerr << "클라이언트 연결 수락 실패" << endl;
            exit(1);
        }

        recv(client_socket, buf_rcv, MAXLINE, 0);
        cout << "receive : " << buf_rcv << endl;
        cout << buf_snd << strlen(buf_rcv) << " : " << buf_rcv << endl;
        send(client_socket, buf_snd, strlen(buf_snd) + 1, 0); //NULL까지 전송
        shutdown(client_socket,SHUT_RDWR);
    }

    return 0;
}