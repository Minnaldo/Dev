#include <cmath>
#include <iostream>

/* 수 이어 쓰기 1 백준_1748( https://www.acmicpc.net/problem/1748 ) */

using namespace std;

int main(int argc, char const *argv[])
{
    int N, ans = 0;
    scanf("%d", &N);

    for (int i = 1; i < 9; i++)
    {
        int tmp = pow(10, i);
        if (N / tmp > 0)
            break;

        ans += (N % tmp) * i;
    }

    printf("%d\n", ans);

    return 0;
}