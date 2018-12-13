#include <arpa/inet.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sys/socket.h>

#define MAXLINE 1024

/** * the source code that cs style network
 *  * Server
 *  * LoopBack IP
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int server_socket;
    int client_socket;

    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;

    char buf_rcv[MAXLINE + 5];
    char buf_snd[MAXLINE + 5];

    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (-1 == server_socket)
    {
        cerr << "server socket 생성 실패\n";
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;   // 프로토콜
    server_addr.sin_port = htons(9999); // 열어둘 포트 번호
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (-1 == bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)))
    {
        cerr << "binding error\n";
        exit(1);
    }

    // 서버는 계속해서 확인하고 응답해야하므로 반복문을 통해 반복한다
    while (1)
    {
        // 포트번호 열어두고 listen
        if (-1 == listen(server_socket, 5)) // 소켓을 수동 대기모드로 설정
        {
            cerr << "대기상태 모드 설정 실패\n";
            exit(1);
        }

        socklen_t client_addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (-1 == client_socket)
        {
            cerr << "클라이언트 연결 수락 실패\n";
            exit(1);
        }

        char temp[20]; //접속한 클라이언트의 IP주소를 담을 배열
        inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, temp, sizeof(temp));
        cout << "Server : " << temp << " client connected\n";

        recv(client_socket, buf_rcv, MAXLINE, 0);
        cout << "receive : " << buf_rcv << "\n";
        cout << buf_snd << strlen(buf_rcv) << " : " << buf_rcv << "\n";
        send(client_socket, buf_snd, strlen(buf_snd) + 1, 0); //NULL까지 전송
        shutdown(client_socket, SHUT_RDWR);                   //클라이언트와 연결된 소켓 제거
    }
    shutdown(server_socket, SHUT_RDWR);

    return 0;
}