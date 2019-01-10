#include <arpa/inet.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sys/socket.h>

/**
 *  * 전송 성공 그러나, 원래 파일 값 뒤에 쓰레기값이 붙는다
 */

// #define local_host "127.0.0.1"   서버는 주소 설정이 필요 없다
#define BUF_SIZE 1024
#define PORT 9999
#define fileDir "./FileTransferTest/"

using namespace std;

int main(int argc, char const *argv[])
{
    int server_Socket;
    int client_Socket;
    int SocketOpt;

    struct sockaddr_in server_Addr;
    struct sockaddr_in client_Addr;

    char buf_rcv[BUF_SIZE];
    char buf_snd[BUF_SIZE];

    server_Socket = socket(PF_INET, SOCK_STREAM, 0);

    if (server_Socket == -1)
    {
        // error_handling
        cout << "Socket Error" << endl;
        exit(1);
    }

    memset(&server_Addr, 0, sizeof(server_Addr));    //구조체라서 초기화 필요
    server_Addr.sin_family = AF_INET;                //sin_family : socket_Internet_family
    server_Addr.sin_port = htons(PORT);              //sin_port : socket_internet_port, htons : host ~~~
    server_Addr.sin_addr.s_addr = htonl(INADDR_ANY); //INADDR_ANY : allow all addr

    SocketOpt = 1;                                                                      //Socket Option
    setsockopt(server_Socket, SOL_SOCKET, SO_REUSEADDR, &SocketOpt, sizeof(SocketOpt)); // bind 에러시 포트를 다시 사용할 수 있도록 해주는 부분

    // REVIEW 2번째 인자를 왜 이렇게 해야되는가?
    // ! 코드 작성 실수 !! bind() 내에 비교문을 넣어 에러가 발생하였음
    // ! 이런 사소한 실수는 항상 조심하고 또 조심해야 함!
    if (bind(server_Socket, (struct sockaddr *)&server_Addr, sizeof(server_Addr)) == -1)
    {
        //error_hadling
        cout << "Binding Error" << endl;
        exit(1);
    }

    if (listen(server_Socket, 5) == -1) //소켓 수동 모드
    {
        //error_handling
        cout << "Listenning Error" << endl;
        exit(1);
    }

    while (true)
    {
        socklen_t client_Addr_size = sizeof(client_Addr); //REVIEW  why need client_Addr_size;
        client_Socket = accept(server_Socket, (struct sockaddr *)&client_Addr, &client_Addr_size);

        if (client_Socket == -1)
        {
            //accept error_handling, 클라이언트 연결 수락 실패
            cout << "Accept Error" << endl;
            exit(1);
        }

        char temp[20];
        inet_ntop(AF_INET, &client_Addr.sin_addr.s_addr, temp, sizeof(temp)); // 클라이언트의 주소를 가져옴
        cout << "Client Connection Success" << endl;

        int rcv_Byte = recv(client_Socket, buf_rcv, BUF_SIZE, 0);
        cout << "Request File : " << buf_rcv << endl;
        if (rcv_Byte < 0)
        {
            //error handling
            cout << "receive error" << endl;
            exit(1);
        }
        else
        {
            cout << "Receive Size : " << sizeof(buf_rcv) << " File Name : " << buf_rcv << endl;

            string dir = fileDir;
            dir += buf_rcv; // 파일 이름과 경로 설정

            ifstream file;
            file.open(dir, ios::in | ios::binary); //  buf_rcv : 전송할 파일 이름을 담고잇는 char형 배열

            if (file.is_open())
            {
                while (!file.eof())
                {
                    file.read(buf_snd, sizeof(buf_snd));
                    send(client_Socket, buf_snd, sizeof(buf_snd), 0);
                }
                file.close(); // 열린 파일 닫기

                string str = "Transmission Complete";
                send(client_Socket, str.c_str(), sizeof(str.c_str()), 0);

                if (shutdown(client_Socket, SHUT_RDWR) == -1) // 전송 소켓 닫음
                {
                    // error_handling
                    cout << "ShutDown Error" << endl;
                    exit(1);
                }
                else
                {
                    cout << "Shutdown Complete" << endl;
                    break;
                }
            }
            else
            {
                //error_handling
                cout << "File open error" << endl
                     << "program is terminated" << endl;
                exit(1);
            }
        }
    } //end while

    return 0;
}
