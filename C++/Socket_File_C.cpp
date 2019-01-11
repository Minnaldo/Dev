#include <arpa/inet.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sys/socket.h>

/**
 *  * 전송 성공
 *  * 파일의 내용이 깨지는 현상 발생
 */

#define BUF_SIZE 1024
#define local_host "127.0.0.1"
#define PORT 9999

using namespace std;

int main(int argc, char const *argv[])
{
    char buf_rcv[BUF_SIZE];
    char buf_snd[BUF_SIZE];

    int client_Socket = socket(PF_INET, SOCK_STREAM, 0);

    if (client_Socket == -1)
    {
        //error_handling
        cout << "Socket Error" << endl;
        exit(1);
    }

    struct sockaddr_in server_Addr;
    server_Addr.sin_family = AF_INET;
    server_Addr.sin_addr.s_addr = inet_addr(local_host);
    server_Addr.sin_port = htons(PORT);

    socklen_t client_Size = sizeof(server_Addr);

    if (connect(client_Socket, (struct sockaddr *)&server_Addr, client_Size) == -1)
    {
        // erroer_handling
        cout << "Connect Eorror" << endl;
        exit(1);
    }
    else
    {
        cout << "Connection Complete" << endl;
    }

    while (true)
    {
        string filename = "testText.txt";
        // cout << "input the file name" << endl;
        // cin >> filename;
        strcpy(buf_snd, filename.c_str());

        if (send(client_Socket, buf_snd, sizeof(buf_snd), 0) == -1)
        {
            //error handling
            cout << "Sending Error" << endl;
            exit(1);
        }

        string fileSaveDir = "./Client_Test.txt";
        fstream fin;
        fin.open(fileSaveDir, ios::out|ios::binary);

        if (fin.is_open())
        {
            char size[4] = {0};
            cout << "File Opend" << endl;
            recv(client_Socket, size, sizeof(buf_rcv), 0); // 파일 크기 수신
            int fileSize = *((int *)size);                 // TODO 다른 소켓 정수보내는법을 찾아보자
            cout << "File Size : " << fileSize << endl;

            int rcv_Byte = recv(client_Socket, buf_rcv, sizeof(buf_rcv), 0);
            if (rcv_Byte >= 0)
            {
                // TODO
                // ! 수신 된 파일은 바이너리 모드로 aaplication/octet-stream charset=binay로 되어있음
                // ! 테스트 파일 : text/plain; charset=utf-8
                while (fileSize > 0)
                {
                    fileSize -= rcv_Byte;
                    // cout<<buf_rcv<<endl;
                    fin.write(reinterpret_cast<const char *>(&buf_rcv), rcv_Byte);
                    // memset(buf_rcv, 0, sizeof(buf_rcv));
                    // cout<<"test"<<buf_rcv<<endl;
                    rcv_Byte = recv(client_Socket, buf_rcv, sizeof(buf_rcv), 0);
                }
                cout << "File Download Complete" << endl;
                fin.close(); // 열린 파일 닫기
                memset(buf_rcv, 0, sizeof(buf_rcv));
                recv(client_Socket, buf_rcv, sizeof(buf_rcv), 0);
                // cout << buf_rcv << endl; // ! 메세지가 잘림
                shutdown(client_Socket, SHUT_RDWR);
                return 0;
            }
            else
            {
                //error_handling
                cout << "Error from File receive" << endl;
                exit(1);
            }
        }
        else
        {
            //error_handling
            cout << "File open Error" << endl;
            exit(1);
        }
    }

    return 0;
}