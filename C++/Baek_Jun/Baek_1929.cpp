#include <iostream>

/** 소수 구하기 백준_1929 ( https://www.acmicpc.net/problem/1929 )
 *
 */

using namespace std;

bool arr[1000001];

int main(int argc, char const *argv[])
{
    // 에라토스 테네스의 체
    arr[1] = true;
    for (int i = 2; i <= 1000000; i++)
    {
        if (!arr[i])
            for (int j = i * 2; j <= 1000000; j += i)
                arr[j] = true;
    }

    int M,N;
    scanf("%d %d", &M, &N);
    for(int i = M; i<= N; i++)
    {
        if(!arr[i])
            printf("%d\n",i);
    }
    return 0;
}