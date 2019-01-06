#include <arpa/inet.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sys/socket.h>

#define MAXLINE 1024

/** * the source code that cs style network
 *  * Server
 *  * LoopBack IP
 *  * Complete
 *  * Socket(소켓 선언) -> Binding(IP Addr과 Socket을 결합) -> Listen(클라이언트의 접속 대기) -> Accept(클라이언트와 접속 수락) ==> behave
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int server_socket;
    int client_socket;

    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;

    char buf_rcv[MAXLINE]; // 수신 버퍼
    char buf_snd[MAXLINE]; // 송신 버퍼

    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (-1 == server_socket)
    {
        cerr << "server socket 생성 실패\n";
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;                // 프로토콜
    server_addr.sin_port = htons(9999);              // 열어둘 포트 번호
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY ==> 모든 주소 허용

    if (-1 == bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)))
    {
        cerr << "binding error\n";
        exit(1);
    }

    // 서버는 계속해서 확인하고 응답해야하므로 반복문을 통해 반복한다
    while (true)
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
        cout << temp << " client connected\n";

        // ! 최대 버퍼 사이즈(MAXLINE) 만큼의 데이터를 가져와 buf에 저장
        // ! recv함수는 가져온 byte길이를 리턴
        int result = recv(client_socket, buf_rcv, MAXLINE, 0);

        if (result < 0)
        {
            cerr << "receive Error" << endl;
            break;
        }
        else if (result > 0)
        {
            cout << "rcv_size : " << strlen(buf_rcv) << "    receive : " << buf_rcv << "\n";
            // cout << buf_snd << strlen(buf_rcv) << " : " << buf_rcv << "\n";
            string rcv_str = buf_rcv;
            strcpy(buf_snd, rcv_str.c_str());
            send(client_socket, buf_snd, sizeof(buf_snd), 0); //NULL까지 전송, echo
            shutdown(client_socket, SHUT_RDWR);               //클라이언트와 연결된 소켓 제거
        }
        else
        {
            cout << "Client send to me message that size 0" << endl;
            break;
        }

        memset(buf_snd, 0x00, MAXLINE);
        memset(buf_rcv, 0x00, MAXLINE);
    }
    shutdown(server_socket, SHUT_RDWR);

    return 0;
}