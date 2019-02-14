#include <fstream>
#include <iostream>

using namespace std;

/** 쉬운 계단수 백준_10844 (https://www.acmicpc.net/problem/10844)
 *  * 전체적인 틀을 그려보면 방사형태로 퍼짐 ==> 2차원 배열을 이용하여 풀면 편하다
 *  ! 자료형 조심! answer의 자료형이 long long이 되어야 한다
 */

long long dp[10][101];

long long solution(int n)
{
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j > 0 && j < 9)
            {
                dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % 1000000000;
            }
            else if (j == 0)
            {
                dp[j][i] = (dp[j + 1][i - 1]) % 1000000000;
            }
            else if (j == 9)
            {
                dp[j][i] = (dp[j - 1][i - 1]) % 1000000000;
            }
        }
    }

    long long answer = 0;

    for (int i = 0; i < 10; i++)
    {
        answer += dp[i][n] % 1000000000;
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    fstream fs("input.txt");
    int n;
    // cin >> n;

    while (fs >> n)
    {
        // pre-processing
        for (int i = 1; i < 10; i++)
        {
            dp[i][1] = 1;
        }
        cout << solution(n) << endl;
    }
    return 0;
}