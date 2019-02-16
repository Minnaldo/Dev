#include <iostream>
#include <time.h>

/** 백준_11057 오르막 수 ( https://www.acmicpc.net/problem/11057 )
 *  * Dynamic Programming
 */

using namespace std;

int dp[10][1001];

int solution(int N)
{
    int answer = 0;

    for (int j = 2; j <= N; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int k = 0; k <= i; k++)
            {
                dp[i][j] = (dp[i][j] + dp[k][j-1])%10007;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        answer += dp[i][N];
    }

    return answer % 10007;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N;
    cin>>N;

    for (int i = 0; i < 10; i++)
    {
        dp[i][1] = 1;
    }

    // N = 1; //10
    // N = 2; //55
    // N = 3; //220

    cout << solution(N) << endl;

    return 0;
}