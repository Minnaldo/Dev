//============================================================================
// Name        : linuxsrv.cpp
// Author      : jhjung
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>

// 최대 접속대기 클라이언트 수
const int MAXCONNECTIONS = 5;

// 대기 버퍼 크기
const int MAXWAITBUFSIZE = 4096;

// SEND용 버퍼의 크기
const int MAXSENDBUFSIZE = 1024;

// RECV용 버퍼의 크기
const int MAXRECEIVEBUFSIZE = 1024;

// 메세지 타입
#define ODSP_COMMAND 1
#define ODSP_REQUEST 2
#define ODSP_ACK 3
#define ODSP_ECHO 4
#define ODSP_END 5

// 메세지 헤더
struct ODSP_HDR
{
    unsigned int msgType;
    unsigned int msgLen;
};

using namespace std;


int main ()
{
    // 버퍼에서 헤더를 분석할 순서 인지를 판별하기위한 변수
    bool isHeader = true;

    // 보낸 데이터 길이
    unsigned int sendByteLen;

    // 받은 데이터, 보낸 데이터 바이트 길이를 받는 변수
    unsigned int byteLen;

    // 데이터를 처리할 수 있는 길이가 되었는지 확인용 변수
    // 현재 대기 버퍼안에 있는 데이터의 길이를 저장
    unsigned int curLen;

    // listen socket file discriptor
    int listenSockFD;

    // client socket file discriptor
    int clientSockFD;

    // 버퍼의 인덱스 포인터
    char *ptrRecvBufIdx = 0;

    // data 정리용 포인터
    char *ptrDataSortingIdx = 0;

    // send buf 용 인덱스 포인터
    char *ptrSendBufIdx = 0;

    // RECV용 버퍼 선언
    char buf[MAXRECEIVEBUFSIZE];

    // SEND용 버퍼 선언 (헤더 + 메세지)
    char bufSend[MAXSENDBUFSIZE];

    // message SEND용 버퍼 선언
    char bufSendMsg[MAXSENDBUFSIZE];

    // 시스템용 대기 버퍼 선언
    char bufWait[MAXWAITBUFSIZE];

    // 헤더 처리 버퍼
    char bufHdr[MAXWAITBUFSIZE];

    // 메세지 처리 버퍼
    char bufMsg[MAXWAITBUFSIZE];

    // 대기 버퍼 스왑용 버퍼
    char bufTemp[MAXWAITBUFSIZE];

    string Msg = "";

    // 소켓 주소 구조체 선언
    sockaddr_in server_addr, client_addr;

    // 송신용 메세지 헤더 구조체 선언
    ODSP_HDR hdr;

    // 메세지 헤더 구조체 포인터 선언
    ODSP_HDR *recv_hdr;

    // listen socket 생성
    listenSockFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(listenSockFD < 0)
    {
        cout << endl << "socket create error" << endl;
        return 0;
    }

    // 소켓 초기화
    int on = 1;
    if(setsockopt(listenSockFD, SOL_SOCKET, SO_REUSEADDR, (const char*) &on, sizeof(on)) < 0)
    {
        cout << endl  << "set option curLen = 0;화error!!" << endl;
        return 0;
    }

    // 서버에서 연결을 수락할 IP 주소 설정
    // INADDR_ANY -> 모든 주소 허용
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // AF_INET ->  ipv4
    server_addr.sin_family = AF_INET;

    // 포트 셋팅
    server_addr.sin_port = htons(30000);

    // listen socket에 주소 할당
    if(bind(listenSockFD, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
    {
        cout << endl << "bind error" << endl;
        return 0;
    }

    cout << "server running. waiting client..." << endl;

    // passive 대기 상태로 client의 접속을 대기
    // client 에서 connect를 통해 접속 시도 시 3-way handshake 가 일어남
    if(listen(listenSockFD, MAXCONNECTIONS) < 0)
    {
        cout << endl << "listen error" << endl;
        return 0;
    }

    int clientAddrSize =  sizeof(client_addr);

    while(true)
    {
        // 대기버퍼에 있는 데이터 길이 초기
        curLen = 0;

        // 대기 버퍼 초기화
        memset(bufWait, 0, MAXWAITBUFSIZE);

        // 버퍼 포인터 초기화
        // 대기 버퍼의 시작 주소를 가진다.
        ptrRecvBufIdx = bufWait;

        // client에 대해 허용
        clientSockFD = accept(listenSockFD, (struct sockaddr *) &client_addr, (socklen_t *) &clientAddrSize);

        if(clientSockFD < 0)
        {
            cout << endl << "accept error" << endl;
            return 0;
        }

        cout << endl << "client accepted" << endl;
        cout << "address : " << inet_ntoa(client_addr.sin_addr) << endl;
        cout << "port : " << ntohs(client_addr.sin_port) << endl;

        // data 수신 처리
        while(true)
        {
            // receive 버퍼 초기화
            memset(buf, 0, MAXRECEIVEBUFSIZE);

            // data를 가져옴
            // 최대 버퍼 사이즈 만큼의 데이터를 가져와서 buf에 저장
            // recv 함수는 가져온 byte의 길이를 return
            byteLen = recv(clientSockFD, buf, MAXRECEIVEBUFSIZE, 0);

            if(byteLen == 0)    // 받은 data가 0 : 클라이언트가 접속을 끊었거나, 데이터를 전송하지 않음
            {
                cout << endl << "client " << inet_ntoa(client_addr.sin_addr) << " closed." << endl;
                close(clientSockFD);
                break;
            }

            if(byteLen > MAXRECEIVEBUFSIZE) // 받은 data > 수신 버퍼 최대 크기 :
            {
                cout << endl << "client " << inet_ntoa(client_addr.sin_addr) << " closed." << endl;
                close(clientSockFD);
                break;
            }

            if(byteLen > 0)
            {
                memcpy(ptrRecvBufIdx, buf, byteLen);    // 받아온 길이만큼 buf (임시 수신 데이터 버퍼)를 ptrRecvBufIdx에 복사
                curLen += byteLen;
                ptrRecvBufIdx += byteLen;
                byteLen = 0;

                // 헤더를 분석할 순서
                if(isHeader)
                {
                    // 헤더 길이 이상의 data가 있는지 확인
                    if(curLen >= sizeof(recv_hdr))
                    {
                        memset(bufHdr, 0, sizeof(bufHdr));
                        memcpy(bufHdr, bufWait, sizeof(recv_hdr));
                        bufHdr[sizeof(recv_hdr)] = '\0';
                        recv_hdr = (ODSP_HDR *)bufHdr;

                        // 버퍼의 data를 정리
                        ptrDataSortingIdx = bufWait + sizeof(recv_hdr);
                        memset(bufTemp, 0, sizeof(bufTemp));
                        memcpy(bufTemp, ptrDataSortingIdx, sizeof(bufWait) - sizeof(recv_hdr));
                        memset(bufWait, 0, sizeof(bufWait));
                        memcpy(bufWait, bufTemp, sizeof(bufTemp));

                        curLen -= sizeof(recv_hdr);
                        ptrRecvBufIdx -= sizeof(recv_hdr);
                        isHeader = false;
                    }
                }

                if(!isHeader)
                {
                    // 분석된 헤더의 메세지 길이 정보를 통해 현재 버퍼에 메세지 길이 이상의 data가 있는지 확인
                    if(curLen >= recv_hdr->msgLen)
                    {
                        memset(bufMsg, 0, sizeof(bufMsg));
                        memcpy(bufMsg, bufWait, recv_hdr->msgLen);
                        bufMsg[recv_hdr->msgLen] = '\0';

                        // 버퍼의 data를 정리
                        ptrDataSortingIdx = bufWait + recv_hdr->msgLen;
                        memset(bufTemp, 0, sizeof(bufTemp));
                        memcpy(bufTemp, ptrDataSortingIdx, sizeof(bufWait) - recv_hdr->msgLen);
                        memset(bufWait, 0, sizeof(bufWait));
                        memcpy(bufWait, bufTemp, sizeof(bufTemp));

                        curLen -= recv_hdr->msgLen;
                        ptrRecvBufIdx -= recv_hdr->msgLen;
                        isHeader = true;

                        if(recv_hdr->msgType == ODSP_COMMAND)
                        {
                            cout << endl << "received command message" << endl;
                            cout << "message length is " << recv_hdr->msgLen << "byte" << endl;
                            cout << "receive message : " << bufMsg << endl;

                            Msg = "received command message";
                            strcpy(bufSendMsg, Msg.c_str());

                            memset(&hdr, 0, sizeof(hdr));
                            hdr.msgType = ODSP_ACK;
                            hdr.msgLen = Msg.length();

                            ptrSendBufIdx = bufSend;
                            memcpy(ptrSendBufIdx, &hdr, sizeof(hdr));
                            ptrSendBufIdx = ptrSendBufIdx + sizeof(hdr);
                            memcpy(ptrSendBufIdx, bufSendMsg, hdr.msgLen);

                            sendByteLen = send(clientSockFD, bufSend, sizeof(hdr) + hdr.msgLen, 0);

                            if(sendByteLen < 0)
                            {
                                cout << endl << "send error" << endl;
                                return 0;
                            }
                        }
                        else if(recv_hdr->msgType == ODSP_REQUEST)
                        {
                            cout << endl << "received request message" << endl;
                            cout << "message length is " << recv_hdr->msgLen << "byte" << endl;
                            cout << "receive message : " << bufMsg << endl;
                        }
                        else if(recv_hdr->msgType == ODSP_ACK)
                        {
                            cout << endl << "received ack message" << endl;
                            cout << "message length is " << recv_hdr->msgLen << "byte" << endl;
                            cout << "receive message : " << bufMsg << endl;
                        }
                        else if(recv_hdr->msgType == ODSP_ECHO)
                        {
                            cout << endl << "received echo message" << endl;
                            cout << "message length is " << recv_hdr->msgLen << "byte" << endl;
                            cout << "receive message : " << bufMsg << endl;

                            Msg = bufMsg;
                            strcpy(bufSendMsg, Msg.c_str());

                            memset(&hdr, 0, sizeof(hdr));
                            hdr.msgType = ODSP_ECHO;
                            hdr.msgLen = recv_hdr->msgLen;

                            ptrSendBufIdx = bufSend;
                            memcpy(ptrSendBufIdx, &hdr, sizeof(hdr));
                            ptrSendBufIdx = ptrSendBufIdx + sizeof(hdr);
                            memcpy(ptrSendBufIdx, bufSendMsg, hdr.msgLen);

                            sendByteLen = send(clientSockFD, bufSend, sizeof(hdr) + hdr.msgLen, 0);

                            if(sendByteLen < 0)
                            {
                                cout << endl << "send error" << endl;
                                return 0;
                            }
                        }
                        else if(recv_hdr->msgType == ODSP_END)
                        {
                            cout << endl << "received end message" << endl;
                            cout << "message length is " << recv_hdr->msgLen << "byte" << endl;
                            cout << "receive message : " << bufMsg << endl;
                        }
                        else
                        {
                            cout << endl << "received unknown message" << endl;
                            cout << "exit server" << endl;
                            close(clientSockFD);
                            break;
                        }
                    }
                }
            } //byteLen > 0
        } //recv while
    } //accept while

    close(listenSockFD);

    cout << "server end" << endl;

    return 0;
}