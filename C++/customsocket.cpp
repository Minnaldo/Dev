#include <fstream>
#include <iostream>
#include <string>

#include <arpa/inet.h>
#include <cstring>
#include <sys/socket.h>

#define BUF_SIZE 1024

using namespace std;

template <typename T>
class Socket
{
  public:
    Socket(int port = 9999)
    {
        memset(&server_Addr, 0, sizeof(server_Addr));

        server_Socket = socket(PF_INET, SOCK_STREAM, 0);

        if (server_Socket == -1)
        {
            // error_handling
            cout << "Socket Error" << endl;
            exit(1);
        }

        server_Addr.sin_family = AF_INET;
        server_Addr.sin_port = htons(port);
        server_Addr.sin_addr.s_addr = htonl(INADDR_ANY);

        // SocketOpt = 1;
        // setsockopt(server_Socket, SOL_SOCKET, SO_REUSEADDR, &SocketOpt, sizeof(SocketOpt));

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
    }

    void fileTransfer(string filename)
    {
        fstream file(filename.c_str(), ios::binary | ios::in);
        file.seekg(0, ios::end);
        char file_size[4] = *((int *)file.tellg());
        send(client_Socket, file_size, sizeof(file_size), 0); // 파일 크기 전송

        while (!file.eofbit)
        {
            file.read(buf_snd, sizeof(buf_snd));
            send(client_Socket, buf_snd, sizeof(buf_snd), 0);
        }
        file.close();
    }

    void sendMsg(string msg)
    {
        memcpy(buf_snd, msg.c_str(), sizeof(msg.c_str()));
        send(client_Socket, buf_snd, sizeof(buf_snd), 0);
    }

    void recvMsg()
    {
        recv(client_Socket, buf_rcv, sizeof(buf_rcv), 0);
    }

    void error_handling()
    {

    }

  private:
    struct sockaddr_in server_Addr;
    struct sockaddr_in client_Addr;

    char buf_rcv[BUF_SIZE];
    char buf_snd[BUF_SIZE];

    int server_Socket;
    int client_Socket;
};