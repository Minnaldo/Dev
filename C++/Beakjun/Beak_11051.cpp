#include <iostream>

using namespace std;

/** 이항 계수 2 백준_11051 (https://www.acmicpc.net/problem/11051)
 *  * 이항계수를 조합으로 나타낼 수 있다.
 *  * 본 문제에서는 크기때문에 미리 10007을 나누어주어야 틀리지 않는다
 *  NOTE Combination implement
 */

int dp[1001][1001];

int solution(int n, int r)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= r; j++)
        {
            if (j == 0 || j == i)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%10007;
            }
        }
    }

    return dp[n][r] % 10007;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r;
    cin >> n >> r;
    cout << solution(n, r) << endl;

    return 0;
}