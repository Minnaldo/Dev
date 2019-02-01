#include <arpa/inet.h>
#include <iostream>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define PORT 9999
#define Address "127.0.0.1"

using namespace std;

int main(int argc, char const *argv[])
{
    char buf_rcv[BUF_SIZE], buf_snd[BUF_SIZE];
    struct sockaddr_in server_Addr;

    int Client_Socket = socket(PF_INET, SOCK_STREAM, 0);

    if (Client_Socket == -1)
    {
        cout << "error" << endl;
        exit(1);
    }

    server_Addr.sin_family = AF_INET;
    server_Addr.sin_addr.s_addr = inet_addr(Address);
    server_Addr.sin_port = htons(PORT);

    socklen_t client_len = sizeof(server_Addr);

    if (connect(Client_Socket, (struct sockaddr *)&server_Addr, client_len) == -1)
    {
        cout << "connect error" << endl;
        exit(1);
    }
    else
    {
        cout << "connect complete" << endl;
    }

    // 실행 할 로직 작성
    while (true)
    {
    }

    shutdown(Client_Socket, SHUT_RDWR);
    return 0;
}
