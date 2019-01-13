#include <arpa/inet.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>

/**
 *  * 텍스트 파일, 이미지 전송 성공
 *  TODO file header struct define
 *  TODO multiple client socket communication, use thread
 *  ? 파일헤더 구조체에는 어떠한 것들을 넣는것이 좋을까??
 */

// #define local_host "127.0.0.1"   서버는 주소 설정이 필요 없다
#define BUF_SIZE 1024
#define PORT 9999
#define fileDir "./FileTransferTest/"

using namespace std;

struct FILEHEADER
{
    char fileName[256];
    char fileExt[256];
    long long fileSize = 0;
};

void printByte(char *buf)
{
    int size = sizeof(buf) / sizeof(buf[0]);
    cout << "'";
    for (int i = 0; i < size; i++)
    {
        cout << buf[i];
    }
    cout << "'";
}

void error_handling(string str)
{
    fstream log_File("./server_Log.txt", ios::out);

    if (log_File.is_open())
    {
        log_File << str;
    }
    cerr << str;
    exit(1);
}

int main(int argc, char const *argv[])
{
    int server_Socket;
    int client_Socket;
    int SocketOpt;

    struct sockaddr_in server_Addr;
    struct sockaddr_in client_Addr;

    FILEHEADER *fHeader;

    char buf_rcv[BUF_SIZE];
    char buf_snd[BUF_SIZE];

    char cAddr[20];

    server_Socket = socket(PF_INET, SOCK_STREAM, 0); // 서버 소켓 선언

    if (server_Socket == -1)
        error_handling("Socket Error");

    memset(&server_Addr, 0, sizeof(server_Addr));    //구조체라서 초기화 필요
    server_Addr.sin_family = AF_INET;                //sin_family : socket_Internet_family
    server_Addr.sin_port = htons(PORT);              //sin_port : socket_internet_port, htons : host-
    server_Addr.sin_addr.s_addr = htonl(INADDR_ANY); //INADDR_ANY : allow all addr

    SocketOpt = 1;                                                                      //Socket Option
    setsockopt(server_Socket, SOL_SOCKET, SO_REUSEADDR, &SocketOpt, sizeof(SocketOpt)); // bind 에러시 포트를 다시 사용할 수 있도록 해주는 부분

    // REVIEW 2번째 인자를 왜 이렇게 해야되는가?
    // ! 코드 작성 실수 !! bind() 내에 비교문을 넣어 에러가 발생하였음
    // ! 이런 사소한 실수는 항상 조심하고 또 조심해야 함!
    if (bind(server_Socket, (struct sockaddr *)&server_Addr, sizeof(server_Addr)) == -1)
        error_handling("Binding Error");

    if (listen(server_Socket, 5) == -1) //소켓 수동 모드
        error_handling("Listenning Error");

    while (true)
    {
        socklen_t client_Addr_size = sizeof(client_Addr); //REVIEW  why need client_Addr_size, ↓ 필요
        client_Socket = accept(server_Socket, (struct sockaddr *)&client_Addr, &client_Addr_size);

        cout << "Server is waiting for Client..." << endl;

        if (client_Socket == -1)
            error_handling("Accept Error");

        inet_ntop(AF_INET, &client_Addr.sin_addr.s_addr, cAddr, sizeof(cAddr)); // 클라이언트의 주소를 가져옴
        cout << "Client Connection Success" << endl;

        int rcv_Byte = recv(client_Socket, buf_rcv, BUF_SIZE, 0);
        cout << "Request File : " << buf_rcv << endl;

        if (rcv_Byte < 0)
        {
            error_handling("receive error");
        }
        else
        {
            cout << "Receive Size : " << sizeof(buf_rcv) << endl
                 << " Rcv Data : " << buf_rcv << endl;

            string dir = fileDir;
            dir += buf_rcv; // 파일 이름과 경로 설정

            ifstream fout;
            fout.open(dir, ios::binary); // NOTE file read configuration, 파일 경로로 파일 열기

            if (fout.is_open())
            {
                cout << "File Opend" << endl;
                // 연 파일의 크기를 가져온다,
                fout.seekg(0, ios::end); // 파일의 마지막으로 파일포인터를 옮긴다
                int size = fout.tellg(); // 파일포인터가 몇번째인지 출력 : 이는 바이트 크기이므로 곧 파일의 크기가 됨
                char fileSize[4] = {0};
                *((int *)fileSize) = size;
                send(client_Socket, fileSize, sizeof(fileSize), 0); // 파일 크기를 보낸다
                cout << "File Size : " << size << endl;             // @param File Size
                fout.seekg(0, ios::beg);                            // ! 파일 포인터를 끝으로 보내 파일의 크기를 구했으면, 다시 파일의 처음으로 포인터를 보내 파일을 읽고 전송해야 한다
                //NOTE
                while (!fout.eof())
                {
                    // ? fout.read(); 와 fout >> buf_snd의 차이점은 무엇??
                    fout.read(buf_snd, sizeof(buf_snd));
                    // fout >> buf_snd;
                    // printByte(buf_snd);
                    send(client_Socket, buf_snd, sizeof(buf_snd), 0);
                }
                fout.close(); // 열린 파일 닫기

                string str = "Transmission Complete";
                memcpy(buf_snd, str.c_str(), sizeof(str.c_str()));
                send(client_Socket, buf_snd, sizeof(buf_snd), 0);

                if (shutdown(client_Socket, SHUT_RDWR) == -1) // 전송 소켓 닫음
                    error_handling("ShutDown Error");
                else
                {
                    cout << "Shutdown Complete" << endl;
                    break; // 서버 프로그램을 종료하기 싫으면 break문 지우기
                }
            }
            else
            {
                cout << "program is terminated" << endl;
                error_handling("File open error");
            }
        }
    } //end while

    return 0;
}
