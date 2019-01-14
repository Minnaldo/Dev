#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <pthread.h>
#include <queue>
#include <semaphore.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define LISTEN_QUEUE_SIZE 256
#define PORT 10009

/**
 *  * 전역변수로 accept()가 리턴한 값을 스레드에 전달하여 클라이언트 판단
 */

using namespace std;

// 세마포어 생성
sem_t consume;

int clientNum = 0;
int getFD = -1;
int id = 0;

// 스레드 풀 생성
queue<int> threadPool;

// 스레드에서 실행할 함수 포인터,
void *threadfunc(void *argumentPointer)
{
    int tid = id++; // 스레드마다 id 부여
    int connectFD = -1;

    ssize_t receivedBytes;
    char readBuff[BUFFER_SIZE];
    char sendBuff[BUFFER_SIZE];

    while (1)
    {
        // 스레드를 이용하기 위해서는 consume 세마포어에 값이 1이상 있어야 한다.
        // consume 세마포어를 1 줄인다.(P)
        sem_wait(&consume);

        connectFD = getFD;
        threadPool.push(connectFD);
        getFD = -1; // 전역변수에서 받아온 파일 디스크립터를 초기화

        printf("큐 크기 :: %lu\n", threadPool.size());
        ssize_t receivedBytes;

        int n[2];    // 클라이언트로부터 받아온 숫자들을 저장할 배열
        int sum = 0; // 클라이언트로부터 받아온 숫자의 합을 저장할 변수
        int cnt = 0; // 클라이언트로부터 숫자를 받은 횟수를 카운트

        // 두 수를 받기위해 cnt < 2라는 조건을 이용한다.
        while (cnt < 2)
        {
            receivedBytes = read(connectFD, readBuff, BUFFER_SIZE);
            printf("%lu bytes read\n", receivedBytes);
            readBuff[receivedBytes] = '\0';
            fflush(stdout);

            // 받은 값은 문자열 형식이니 이것을 숫자로 변환해준다.
            n[cnt] = atoi(readBuff);
            printf("id :: %d // input num :: %d\n", tid, n[cnt]);

            sum += n[cnt];
            cnt++;

            // cnt가 2가되면 합계를 내어 클라이언트로 전송해준다.
            if (cnt == 2)
            {
                printf("sum :: %d\n", sum);
                sprintf(sendBuff, "%d", sum);
                write(connectFD, sendBuff, strlen(sendBuff));
            }
        }

        // 계산이 끝나고 스레드 탈출 전 계산을 해준다.
        threadPool.pop(); // 스레드 풀에서 스레드 제거
        clientNum--;      // 접속중인 클라이언트 수 감소
        close(connectFD); // 소켓 닫기
    }

    return NULL;
}

int main()
{
    int i;
    pthread_t threadID[LISTEN_QUEUE_SIZE];

    struct sockaddr_in listenSocket;

    memset(&listenSocket, 0, sizeof(listenSocket));

    listenSocket.sin_family = AF_INET;
    listenSocket.sin_addr.s_addr = htonl(INADDR_ANY);
    listenSocket.sin_port = htons(PORT);

    int listenFD = socket(AF_INET, SOCK_STREAM, 0);
    int connectFD;

    // 바인딩
    if (bind(listenFD, (struct sockaddr *)&listenSocket, sizeof(listenSocket)) == -1)
    {
        printf("Can not bind.\n");
        return -1;
    }

    // 리스닝
    if (listen(listenFD, LISTEN_QUEUE_SIZE) == -1)
    {
        printf("Listen fail.\n");
        return -1;
    }

    printf("Waiting for clients...\n");

    // 처음에는 스레드가 움직이면 안되니 0으로 초기화한다.
    sem_init(&consume, 0, 0);

    // 스레드 생성(큐 사이즈 만큼)
    for (i = 0; i < LISTEN_QUEUE_SIZE; i++)
        pthread_create(&threadID[i], NULL, threadfunc, (void *)&i);

    ssize_t receivedBytes;
    char readBuff[BUFFER_SIZE];
    char sendBuff[BUFFER_SIZE];

    while (true)
    {
        struct sockaddr_in connectSocket, peerSocket;

        socklen_t connectSocketLength = sizeof(connectSocket);

        /*
     뮤텍스는 이부분에서 락을 걸고 언락을 해주지만,
     세마포어 입장에서는 이 부분에서 P,V가 없어도
         자식 스레드와 충돌이 일어나지 않는다고 생각하기에 이용하지 않았다.
     세마포어 초기화 자체에서 0으로 했기에 자식 스레드가 먼저 돌 일이없다.
    */
        // 어셉트를 메인 스레드에서 진행한다.
        while ((connectFD = accept(listenFD, (struct sockaddr *)&connectSocket, (socklen_t *)&connectSocketLength)) >= 0)
        {
            clientNum++;

            printf("현재 수용 인원 :: %d / %d \n", clientNum, LISTEN_QUEUE_SIZE);
            if (clientNum > LISTEN_QUEUE_SIZE)
            {
                // Send Error(Full)
                sprintf(sendBuff, "%s", "현재 서버 수용 인원이 꽉 차 접속할 수 없습니다. 잠시후 다시 시도하세요.\n");
                write(connectFD, sendBuff, strlen(sendBuff));
                clientNum--;
            }

            else
            {
                // FD를 전역 변수를 이용하여 보낸다.(스레드 인자 사용이 불가능)
                getFD = connectFD;

                // consume 세마포어를 1개 늘려준다.(V)
                sem_post(&consume);
            }
        }
    }
    close(listenFD);

    return 0;
}