#include <arpa/inet.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>

/**
 *  * 텍스트 파일, 이미지 전송 성공
 *  * 파일 이름으로 파일 요청 후, 수신
 *  * 동기화 소켓 프로그래밍
 *  TODO file information that used to define structure type
 *  TODO multiple client socket communication, use thread
 *  TODO 파일에 대한 동기화가 더 필요
 *  ? 파일헤더 구조체에는 어떠한 것들을 넣는것이 좋을까??
 */

#define BUF_SIZE 1024          // 송수신 버퍼 사이즈
#define local_host "127.0.0.1" // 접속할 주소
#define PORT 9999              // 접속할 포트

using namespace std;

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
    fstream log_File("./client_Log.txt", ios::out);

    if (log_File.is_open())
    {
        log_File << str;
    }
    cerr << str;
    exit(1);
}

int main(int argc, char const *argv[])
{
    FILEHEADER *fHeader;

    char buf_rcv[BUF_SIZE];
    char buf_snd[BUF_SIZE];

    int client_Socket = socket(PF_INET, SOCK_STREAM, 0);

    if (client_Socket == -1)
        error_handling("Socket Error");

    struct sockaddr_in server_Addr;
    server_Addr.sin_family = AF_INET;
    server_Addr.sin_addr.s_addr = inet_addr(local_host);
    server_Addr.sin_port = htons(PORT);

    socklen_t client_Size = sizeof(server_Addr);

    if (connect(client_Socket, (struct sockaddr *)&server_Addr, client_Size) == -1)
        error_handling("Connect Eorror");
    else
    {
        cout << "Connection Complete" << endl;
    }

    while (true)
    {
        string strFilename = "testText.txt"; //@param filename
        // string filename = "test_img.jpg";
        memcpy(fHeader->fileName,strFilename.c_str(),sizeof(strFilename.c_str()));

        if (send(client_Socket, buf_snd, sizeof(buf_snd), 0) == -1)
            error_handling("Sending Error");

        string fileSaveDir = "./Client_Test.txt";
        ofstream fin;
        fin.open(fileSaveDir, ios::binary); // NOTE file write configuration

        if (fin.is_open())
        {
            char size[4] = {0};
            cout << "File Opend" << endl;
            recv(client_Socket, size, sizeof(buf_rcv), 0); // 파일 크기 수신
            int fileSize = *((int *)size);                 // TODO 다른 소켓 정수보내는법을 찾아보자
            cout << "File Size : " << fileSize << endl;    // @param File Size

            memset(buf_rcv, 0, sizeof(buf_rcv));
            char tempContent[BUF_SIZE];
            int rcv_Byte = recv(client_Socket, buf_rcv, sizeof(buf_rcv), 0);
            if (rcv_Byte > 0)
            {
                //NOTE
                while (fileSize > 0)
                { //TODO the file have garbage value on this point
                    // buf_rcv배열의 크기만큼 입력을 해서 의도치 않은 쓰레기값이 들어가는 것 같다
                    fileSize -= rcv_Byte;
                    // printByte(buf_rcv);
                    fin.write(buf_rcv, sizeof(buf_rcv));
                    // fin << tempContent;
                    rcv_Byte = recv(client_Socket, buf_rcv, sizeof(buf_rcv), 0);
                }
                cout << "File Download Complete" << endl;
                fin.close(); // 열린 파일 닫기

                // ! 마지막 Transmission Complete 메시지 전송 안됨
                memset(buf_rcv, 0, sizeof(buf_rcv));
                recv(client_Socket, buf_rcv, sizeof(buf_rcv), 0);
                printByte(buf_rcv);
                cout << endl;

                shutdown(client_Socket, SHUT_RDWR);
                return 0;
            }
            else
                error_handling("Error from File receive");
        }
        else
            error_handling("File open Error");
    } //end of while

    return 0;
}