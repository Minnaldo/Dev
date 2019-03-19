#include <iostream>

/** 2xn 타일링2 백준_11727 (https://www.acmicpc.net/problem/11727)
 *  * Finish
 */

using namespace std;

int dp[1001];

int solutionn(int n)
{
    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((dp[i - 2] * 2) + dp[i - 1]) % 10007;
    }
    return dp[n] % 10007;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 3;
    cout << solutionn(n) << endl;
    return 0;
}