#include <iostream>

/** 합 분해 백준_2225 ( https://www.acmicpc.net/problem/2225 )
 *  * 참조 : https://mygumi.tistory.com/135
 *  REVIEW
 */

using namespace std;

long long dp[201][201];

void solution(int n, int k)
{
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int l = 0; l <= j; l++)
                dp[i][j] += (dp[i - 1][j - l]) % 1000000000;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;

    // K가 1일 경우, 0~N 경우의 수는 1이기 때문에 1로 초기화
    for (int i = 0; i <= N; i++)
    {
        dp[1][i] = 1;
    }

    solution(N, K);

    cout << dp[K][N] % 1000000000 << endl;

    return 0;
}