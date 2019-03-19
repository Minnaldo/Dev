#include <iostream>

/** 타일 채우기 백준_2133 ( https://www.acmicpc.net/problem/2133 )
 *  * N이 홀수일 경우에는 채울 수 있는 방법이 없다 ==> dp[i] = 0 ( i가 홀수 일 때 )
 *  * 3x0을 채우는 방법 --> 안채우면 된다 = 1가지
 *  * 3x2를 채우는 방법 --> 3가지
 *  * 3x4를 채우는 방법 --> (3x2를 채우는 방법 x 2 를 제외) 2가지
 *  * 6부터 2씩 증가할때마다 2가지 방법이 늘어남 ==> dp[i] += 2
 *  REVIEW
 */

using namespace std;

int dp[31];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    dp[0] = 1;
    dp[2] = 3;

    if (N % 2 != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 4; i <= N; i += 2)
    {
        dp[i] += (dp[i - 2] * 3);

        // 길이가 늘어날 때마다 추가되는 2가지와 이전에 추가되었었던 두가지 방법을 계속 추가
        for (int j = 4; j <= i; j += 2)
            dp[i] += (dp[i - j] * 2);
    }

    cout << dp[N] << endl;

    return 0;
}