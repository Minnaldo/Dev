#include <arpa/inet.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define local_host "127.0.0.1"
#define PORT 9999

/**
 *  * 전송 성공 그러나, 원래 파일 값 뒤에 쓰레기값이 붙는다
 */

using namespace std;

int main(int argc, char const *argv[])
{
    char buf_rcv[BUF_SIZE];
    char buf_snd[BUF_SIZE];

    int client_Socket = socket(PF_INET, SOCK_STREAM, 0);

    if (client_Socket == -1)
    {
        //error_handling
        cout<<"Socket Error"<<endl;
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
        cout<<"Connect Eorror"<<endl;
        exit(1);
    }
    else
    {
        cout << "Connection Complete" << endl;
    }

    while (true)
    {
        string filename = "test.txt";
        // cout << "input the file name" << endl;
        // cin >> filename;
        strcpy(buf_snd, filename.c_str());

        if (send(client_Socket, buf_snd, sizeof(buf_snd), 0) == -1)
        {
            //error handling
            cout<<"Sending Error"<<endl;
            exit(1);
        }

        string fileSaveDir="./Client_Test.txt";
        ofstream file;
        file.open(fileSaveDir, ios::out | ios::binary);

        if (file.is_open())
        {
            int rcv_Byte = recv(client_Socket, buf_rcv, sizeof(buf_rcv), 0);
            if (rcv_Byte >= 0)
            {
                while (rcv_Byte != 0)
                {
                    file.write(buf_rcv, rcv_Byte);
                    rcv_Byte = recv(client_Socket, buf_rcv, sizeof(buf_rcv), 0);
                }
                cout << "File Download Complete" << endl;
                file.close();   // 열린 파일 닫기
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