#include <sstream>
#include <iostream>

/** 정수삼각형 백준_1932 (https://www.acmicpc.net/problem/1932)
 *  ? 백준에 왜 런타임 에러가?
 *  REVIEW
 */

using namespace std;

int dp[501][501];

int max(int a, int b)
{
    return a > b ? a : b;
}

int solution(int n, int **tri)
{
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(tri[i][j] + dp[i - 1][j - 1], tri[i][j] + dp[i - 1][j]);
        }
    }

    int answer = dp[n][0];
    for (int i = 1; i <= n; i++)
    {
        answer = max(answer, dp[n][i]);
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    stringstream ss;
    string str = "5 7 3 8 8 1 0 2 7 4 4 4 5 2 6 5";
    ss.str(str);
    int T;
    ss >> T;

    int **tri = new int *[T + 1];
    for (int i = 1; i <= T; i++)
    {
        tri[i] = new int[i];
        for (int j = 1; j <= i; j++)
        {
            int tmp;
            ss >> tmp;
            tri[i][j] = tmp;
        }
    }

    dp[1][1] = tri[1][1];
    dp[2][1] = tri[2][1] + dp[1][1];
    dp[2][2] = tri[2][2] + dp[1][1];

    cout << solution(T, tri) << endl;

    return 0;
}