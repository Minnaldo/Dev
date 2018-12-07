#include <iostream>

using namespace std;

/** 백준 제곱수_1699 (https://www.acmicpc.net/problem/1699)
 *  TODO 반례체크
 */

int dp[100001];

int min(int a, int b)
{
    return a < b ? a : b;
}

int solution(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j*j <= n; j++)
        {
            int tmp = i - (j * j);
            if (tmp >= 0)
            {
                dp[i] = min(dp[tmp] + 1, dp[i - 1] + 1);
            }
        }
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;   // 142 --> 3
    // int T = 142;

    cout << solution(T) << endl;
    return 0;
}