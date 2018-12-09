#include <iostream>
#include <sstream>

/** 스티커 백준_9465 (https://www.acmicpc.net/problem/9465)
 *  * 스티커 점수의 최대값을 구하라
 *  REVIEW
 */
using namespace std;

int dp[2][100001];

int max(int a, int b)
{
    return a > b ? a : b;
}

int solution(int n, int **arr)
{
    //for문의 위치도 매우 중요하다
    for (int j = 2; j < n; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            if (i == 0)
            {
                dp[i][j] = max(arr[0][j] + dp[1][j - 1], arr[0][j] + dp[0][j - 2]);
                dp[i][j] = max(dp[0][j], arr[0][j] + dp[1][j - 2]);
            }
            else if (i == 1)
            {
                dp[i][j] = max(arr[1][j] + dp[0][j - 1], arr[1][j] + dp[1][j - 2]);
                dp[i][j] = max(dp[1][j], arr[1][j] + dp[0][j - 2]);
            }
        }
    }

    return max(dp[0][n - 1], dp[1][n - 1]);
}

int main(int argc, char const *argv[])
{
    stringstream ss;
    string str = "2 5 50 10 100 20 40 30 50 70 10 60 7 10 30 10 50 100 20 40 20 40 30 50 60 20 80";
    ss.str(str);
    int T;
    ss >> T;

    for (int i = 0; i < T; i++)
    {
        int **arr = new int *[2];
        int n;
        ss >> n;
        for (int j = 0; j < 2; j++)
        {
            arr[j] = new int[n];
            for (int k = 0; k < n; k++)
            {
                int tmp;
                ss >> tmp;
                arr[j][k] = tmp;
            }
        }

        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = dp[1][0] + arr[0][1];
        dp[1][1] = dp[0][0] + arr[1][1];
        cout << solution(n, arr) << endl;
    }
    return 0;
}