#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <queue>
#include <sys/socket.h>
#include <thread>
#include <time.h>

#define BUF_SIZE 1024
#define PORT 9999
#define THREAD_POOL_SIZE 256

/**
 *  * Socket Timeout : 10sec
 *  TODO delete thread id_num in thread queue
 */

using namespace std;

queue<int> thread_Pool;
int thread_id;

// 메시지 송수신 버퍼는 스레드가 실행할 함수에서 선언하여 사용하여야 한다
void ThreadFunc(int &sockFD, int id)
{
    char buf_rcv[BUF_SIZE], buf_snd[BUF_SIZE];
    clock_t start_Time, end_Time;

    cout << id << " Connected" << endl;
    thread_Pool.push(id);
    // 소켓과의 통신 종료는 여기서 종료

    while (true)
    {
        int recvBytes = recv(sockFD, buf_rcv, sizeof(buf_rcv), 0);
        float timeout = (float)((start_Time - clock()) / CLOCKS_PER_SEC);

        // recv()가 0 or -1이면 연결이 끊어진 상태, 받은 메시지의 내용이 아무것도 없는 상태
        if (recvBytes <= 0 || timeout > 10)
        {
            // 스레드 종료시, 메시지 출력
            cout << "No. " << id << " Thread Terminated" << endl;
            cout << "Cuz : ";
            if (recvBytes <= 0)
            {
                thread_terminate_process(sockFD, 1);
                return;
            }
            else
            {
                thread_terminate_process(sockFD, 2);
                return;
            }
        }
        else
        {
            cout << "Client Sends the message what is \"" << buf_rcv << "\"" << endl;
            start_Time = clock();
        }
    }
}

void thread_terminate_process(int &sockFD, int pro_Num)
{

    switch (pro_Num)
    {
        // 서버 수용인원 초과
    case 0:
        cout << "Error : 최대 사용자 수 초과" << endl;
        break;
        // 클라이언트의 접속 종료
    case 1:
        cout << "Client Disconnected" << endl;
        break;
        // 소켓 타임아웃, 일정시간(10sec)동안 클라이언트의 응답 없음
    case 2:
        cout << "Socket Time Out" << endl;
        break;
    }

    shutdown(sockFD, SHUT_RDWR);
    thread_id--;
    return;
}

int main(int argc, char const *argv[])
{
    int server_Socket, client_Socket, SocketOpt;
    struct sockaddr_in server_Addr, client_Addr;
    char cAddr[20]; //클라이언트 주소 저장 변수

    server_Socket = socket(PF_INET, SOCK_STREAM, 0);

    if (server_Socket == -1)
    {
        cout << "error" << endl;
        exit(1);
    }

    memset(&server_Addr, 0, sizeof(server_Addr));
    server_Addr.sin_family = AF_INET;
    server_Addr.sin_port = htons(PORT);
    server_Addr.sin_addr.s_addr = htonl(INADDR_ANY);

    SocketOpt = 1;
    setsockopt(server_Socket, SOL_SOCKET, SO_REUSEADDR, &SocketOpt, sizeof(SocketOpt));

    if (bind(server_Socket, (struct sockaddr *)&server_Addr, sizeof(server_Addr)) == -1)
    {
        cout << "Binding Error" << endl;
        exit(1);
    }

    if (listen(server_Socket, 5) == -1)
    {
        cout << "Listenning Error" << endl;
        exit(1);
    }

    cout << "Server is waiting for client..." << endl;

    while (true)
    {
        socklen_t client_Addr_size = sizeof(client_Addr);
        client_Socket = accept(server_Socket, (struct sockaddr *)&client_Addr, &client_Addr_size);

        if (client_Socket == -1)
        {
            cout << "Accept Error" << endl;
        }
        else
        {
            cout << "현재 접속자 수 : " << thread_id / THREAD_POOL_SIZE << endl;
            if (THREAD_POOL_SIZE > thread_Pool.size())
            {
                // 클라이언트 ip주소 가져오기
                inet_ntop(AF_INET, &client_Addr.sin_addr.s_addr, cAddr, sizeof(cAddr));
                cout << cAddr << " : " << PORT << " Connected" << endl;

                // 람다함수를 이용하여 스레드에서 실행할 함수에 인자를 전달
                // 클라이언트가 접속할때마다 새로운 스레드객체를 생성, 메인 스레드와 별개로 로직 실행
                thread([&]() { ThreadFunc(client_Socket, ++thread_id); }).detach(); // 메인스레드와의 연결이 떨어진 상태로 실행
            }
            else
            {
                char buf_snd[BUF_SIZE];
                string str = "Plz, reconnect after time";
                memcpy(buf_snd, str.c_str(), sizeof(str));
                send(client_Socket, buf_snd, sizeof(buf_snd), 0);
                thread_terminate_process(client_Socket, 0);
            }
        }
    }   // end of while

    return 0;
}