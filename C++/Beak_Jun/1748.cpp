#include <cmath>
#include <iostream>

/* 수 이어 쓰기 1 백준_1748( https://www.acmicpc.net/problem/1748 ) */

using namespace std;

int main(int argc, char const *argv[])
{
    int N, ans = 0, beftmp;
    scanf("%d", &N);

    if (N < 10)
    {
        ans = N;
    }
    else
    {
        int n = N, tmp;
        for (int i = 1; i < 9; i++)
        {
            tmp = pow(10, i);
            if (n / tmp > 0)
                ans += ((n % tmp) - pow(10, i - 1)) * i;
                n -= pow(10, i - 1);
        }
    }
    printf("%d\n", ans);

    return 0;
}