/**
 *  * 2칸전에선 3개 4칸 전에는 2
 *  * N이 홀수일 경우에는 채울 수 있는 방법이 없다 ==> dp[i] = 0 ( i가 홀수 일 때 )
 *
 *  * 3x1을 채우는 방법 --> 없음
 *  * 3x2를 채우는 방법 --> 3가지
 *  * 3x3을 채우는 방법 --> 없음
 *  * 3x4를 채우는 방법 -->
 */

#include <iostream>

using namespace std;

int dp[31];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;

    for (int i = 4; i <= N; i++)
    {
        if (i % 2 != 0)
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] += (dp[i - 2] * 3);
            dp[i] += (dp[i - 4] * 2);
        }
    }

    cout << dp[N] << endl;

    return 0;
}