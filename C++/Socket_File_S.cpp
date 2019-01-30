#include <arpa/inet.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>

/**
 *  * 텍스트 파일, 이미지 전송 성공
 *  * 클라이언트가 요청한 파일 탐색 후, 존재하면 송신
 *  * 동기화 소켓 프로그래밍
 *  * C to Java 소켓통신에서는 구조체를 바이트로 변환하여 전송한다
 *  TODO file information that used to define structure type
 *  TODO multiple client socket communication, use thread
 *  TODO 파일에 대한 동기화가 더 필요
 *  ? 파일헤더 구조체에는 어떠한 것들을 넣는것이 좋을까??
 */

// #define local_host "127.0.0.1"   서버는 주소 설정이 필요 없다
#define BUF_SIZE 1024                 // 송수신 버퍼 사이즈
#define PORT 9999                     // 열어둘 포트
#define fileDir "./FileTransferTest/" // 파일 경로

using namespace std;

// 바이트 출력
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

// 메시지 전송 함수
void send_msg(int &csockFD, string msg)
{
    char buf_snd[BUF_SIZE];
    memcpy(buf_snd, msg.c_str(), sizeof(msg.c_str()));
    send(csockFD, buf_snd, sizeof(buf_snd), 0);
}

// 오픈한 파일의 크기를 가져온다
int getFileSize(ifstream &ifs)
{
    ifs.seekg(0, ios::end); // 파일포인터 이동, 파일 포인터는 바이트 크기
    int size = ifs.tellg();
    ifs.seekg(0, ios::beg); // ! 파일 포인터를 끝으로 보내 파일의 크기를 구했으면, 다시 파일의 처음으로 포인터를 보내 파일을 읽고 전송해야 한다

    return size;
}

// 종료 프로세스
void cSocket_Close(int &csock)
{
    if (shutdown(csock, SHUT_RDWR) == -1) // 전송 소켓 닫음
        error_handling("ShutDown Error");
    else
    {
        cout << "Shutdown Complete" << endl;
    }
}

int main(int argc, char const *argv[])
{
    int server_Socket;
    int client_Socket;
    int SocketOpt;

    struct sockaddr_in server_Addr;
    struct sockaddr_in client_Addr;

    char buf_rcv[BUF_SIZE];
    char buf_snd[BUF_SIZE];

    char cAddr[20];

    server_Socket = socket(PF_INET, SOCK_STREAM, 0); // 서버 소켓 선언

    if (server_Socket == -1)
        error_handling("Socket Error");

    // htons => host byte to network byte in short
    // htonl => host byte to network byte in long
    memset(&server_Addr, 0, sizeof(server_Addr));    //구조체 --> memset()을 통한 초기화 필요
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

    cout << "Server is waiting for Client..." << endl;

    // 서버의 기본설정 이후 클라이언트의 접속을 대기하는 부분
    while (true)
    {
        socklen_t client_Addr_size = sizeof(client_Addr); //REVIEW  why need client_Addr_size, ↓ 필요
        client_Socket = accept(server_Socket, (struct sockaddr *)&client_Addr, &client_Addr_size);  // 멀티스레드 환경에서 client_Socket.accept()후 스레드에 주소값으로 넘겨준다

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
            fout.open(dir, ios::binary);

            if (fout.is_open())
            {
                cout << "File Opend" << endl;
                int size = getFileSize(fout);
                cout << "File Size : " << size << endl;

                char fileSize[4] = {0};                             // int : 4byte, char : 1byte ==> char[4] == int[1]
                *((int *)fileSize) = size;                          // 포인터 형변환, int형 포인터 크기만큼 fileSize에 size를 저장한다
                send(client_Socket, fileSize, sizeof(fileSize), 0); // 파일 크기를 보낸다

                while (!fout.eof())
                {
                    // ? fout.read(); 와 fout >> buf_snd의 차이점은 무엇??
                    fout.read(buf_snd, sizeof(buf_snd)); // buf_snd 사이즈 만큼 읽어온다, 바이너리 모드로 열었기 때문에 바이트 크기만큼 읽어옴
                    // fout >> buf_snd;
                    send(client_Socket, buf_snd, sizeof(buf_snd), 0);
                }
                fout.close(); // 열린 파일 닫기

                // 종료 메시지 전송 후 소켓 닫기/ 주소값으로 소켓 전달
                send_msg(client_Socket, "File Transmission Complete");

                cSocket_Close(client_Socket);
            }
            else
            {
                cout << "program is terminated" << endl;
                error_handling("File open error");
            }
        }
    } //end of while

    return 0;
}
