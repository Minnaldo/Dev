#include <iostream>

/** 소수 백준_2581 ( https://www.acmicpc.net/problem/2581 )
 *  * 소수 찾기 가장 좋은 방법은 에라토스테네스의 체
 */

using namespace std;

bool arr[10001];

int main(int argc, char const *argv[])
{
    // 에라토스 테네스의 체
    arr[1] = true;
    for (int i = 2; i <= 10000; i++)
    {
        if (!arr[i])
            for (int j = i * 2; j <= 10000; j += i)
                arr[j] = true;
    }

    int M, N, min, sum = 0;
    scanf("%d %d", &M, &N);
    min = N;
    for (int i = M; i <= N; i++)
    {
        if (!arr[i])
        {
            sum += i;
            if (min > i)
                min = i;
        }
    }

    if (sum != 0)
        printf("%d\n%d\n", sum, min);
    else
        printf("-1");

    return 0;
}