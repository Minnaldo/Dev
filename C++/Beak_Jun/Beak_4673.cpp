#include <iostream>

/** 셀프 넘버 백준_4673 ( https://www.acmicpc.net/problem/4673 )
 *
 *
 */

using namespace std;

bool dp[10001];

void d(int n)
{
    if (n > 10000)
        return;

    int answer = n + n / 1000 + (n % 1000) / 100 + (n % 100) / 10 + (n % 10) % 10;
    if (answer <= 10000)    // ! 인덱스 접근 에러 발생, 처리 해주어야 함
        dp[answer] = true;
    d(answer);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    for (int i = 1; i < 10000; i++)
    {
        if (!dp[i])
            d(i);
        if (!dp[i])
            cout << i << endl;
    }

    return 0;
}