#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define PORT 9999

using namespace std;

int main(int argc, char const *argv[])
{
    int server_Socket, client_Socket, SocketOpt;

    struct sockaddr_in server_Addr, client_Addr;

    char buf_rcv[BUF_SIZE], buf_snd[BUF_SIZE];
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

        if(client_Socket == -1)
        {
            cout<<"Accept Error"<<endl;
        }
        else{

        }
    }

    return 0;
}

void ThreadFunc(int &sockFD){

}