#include <algorithm>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <time.h>

#define BUF_SIZE 1024
#define PORT 9999
#define Address "127.0.0.1"

/**
 *  * 서버와 메시지/파일 송 수신 프로그램 ( 서버는 스레드를 이용해 멀티 클라이언트에 서비스를 지원 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
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
        int funct;
        cout << "사용할 기능의 번호를 입력해주세요\n1 : 채팅방 입장, 2 : 파일 전송, 3 : 프로그램 종료" << endl;
        cin >> funct;
        switch (funct)
        {
        case 1:
            chatroom(Client_Socket);
            break;
        case 2:
            file_Transfer(Client_Socket);
            break;
        case 3:
            cout << "프로그램을 종료합니다" << endl;
            return 0;
            break;
        }
    }

    shutdown(Client_Socket, SHUT_RDWR);
    return 0;
}

void chatroom(int &socketFD)
{
    char msg_rcv[BUF_SIZE], msg_snd[BUF_SIZE];
    cout << "채팅방에 입장하셨습니다." << endl;
    string tmp = "chatroom";
    memcpy(msg_snd, tmp.c_str(), tmp.size());
    send(socketFD, msg_snd, sizeof(msg_snd), 0); // 서버에 채팅방 기능 요청

    while (true)
    {
        cout << "메시지를 입력해 주세요" << endl;
        cout << "ESC 키를 누르면 채팅방을 종료합니다" << endl;

        string snd_msg;
        cin >> snd_msg;
        string cur_time = getTime();
        memcpy(msg_snd, (cur_time + snd_msg).c_str(), snd_msg.size()); // 메시지 전송 시각과 메시지를 전송

        send(socketFD, msg_snd, sizeof(msg_snd), 0);
        int rcv_Bytes = recv(socketFD, msg_rcv, sizeof(msg_rcv), 0);
        char rTime[8];
        memcpy(rTime, msg_rcv, 8);

        int sndTime = stoi(cur_time.substr(3, 2) + cur_time.substr(6, 2));
        int rcvTime = (rTime[3] + rTime[4] + rTime[6] + rTime[7]);

        // 시간순에 맞춰 메시지 출력
        if (rcv_Bytes > 0 && (sndTime - rcvTime) >= 0)
        {
            cout << msg_rcv << endl;
            cout << msg_snd << endl;
        }
        else
        {
            cout << msg_snd << endl;

            if (rcv_Bytes > 0)
                cout << msg_rcv << endl;
        }

        // TODO
        if (/* if press the esc key */ false)
        {
            return;
        }
    }
}

void file_Transfer(int &socketFD)
{
    char file_rcv[BUF_SIZE], file_snd[BUF_SIZE];
    string tmp = "file_transfer";
    memcpy(file_snd, tmp.c_str(), tmp.size());

    int file_sr;
    cout << "1 : 파일 전송, 2 : 파일 수신" << endl;
    cin >> file_sr;

    switch (file_sr)
    {
    case 1:
        break;

    case 2:
        break;
    }
}

string getTime()
{
    time_t cur_time = time(NULL);
    struct tm *tmp;

    tmp = localtime(&cur_time);
    string header = "00";
    string hour = to_string(tmp->tm_hour);
    string min = to_string(tmp->tm_min);
    string sec = to_string(tmp->tm_sec);

    // time form : hh.mm.ss
    string time = header.substr(0, 2 - hour.size()) + "." + header.substr(0, 2 - min.size()) + "." + header.substr(0, 2 - sec.size());

    return time;
}