#include <fstream>
#include <iostream>

/** 다리 놓기 백준_1010 (https://www.acmicpc.net/problem/1010)
 *  ! 조합문제 : 우측 m개중, 좌측 n개를 고르는 경우의 수를 구한다.
 *  * 접근방식 : 서쪽 사이트 N개와 동쪽 사이트 M개를 이을 수 있는 경우의 수를 계산한다 ==> 결국 이는 조합을 구하는 문제가 된다
 *  * N을 먼저 1개 위치시키고, 나머지 자리에 N-1개를 위치시키는 방법을 찾는다
 */

using namespace std;

int dp[31][31];

// NOTE  combination function
long long solution(int m, int n)
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == j || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[m][n];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    ifstream fs("input.txt");
    int T, n, m;
    while (fs >> T)
    {
        for (int i = 0; i < T; i++)
        {
            fs >> n >> m;
            cout << solution(m, n) << "\n";
        }
    }
    return 0;
}