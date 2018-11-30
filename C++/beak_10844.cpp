#include <iostream>

/** 쉬운 계단수 백준_10844 (https://www.acmicpc.net/problem/10844)
 *
 */

using namespace std;

long long dp[101];

long long solution(int n)
{
    for (int i = 2; i <= n; i++)
    {
        dp[i] = ((dp[i - 1] * 2) - 1)% 1000000000;
    }

    return dp[n] % 1000000000;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    dp[1] = 9;
    cout << solution(n) << endl;
    return 0;
}