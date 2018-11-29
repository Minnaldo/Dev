#include <sstream>
#include <iostream>

/** 정수삼각형 백준_1932 (https://www.acmicpc.net/problem/1932)
 *  NOTE  (http://penglog.tistory.com/59) 참조
 *  ! 수정 필요
 */

using namespace std;

int dp[501][501];

int max(int a1, int a2, int b1, int b2)
{
    return (a1 + a2) > (b1 + b2) ? a1 : b1;
}

// int** tri ==> call by reference
int solution(int n, int **tri)
{
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(tri[i - 1][j - 1], tri[i - 1][j]);

            if (i == (n - 1))
            {
                return dp[i][j];
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    stringstream ss;
    string str = "5 7 3 8 8 1 0 2 7 4 4 4 5 2 6 5";

    int T;
    ss >> T;

    int **tri = new int *[T+1];

    for (int i = 1; i <= T; i++)
    {
        tri[i] = new int[i + 2];
        for (int j = 1; j <= i + 1; j++)
        {
            int tmp;
            ss >> tmp;
            tri[i][j] = tmp;
        }
    }

    dp[1][1] = tri[0][0];
    cout << solution(T, tri) << endl;
    return 0;
}