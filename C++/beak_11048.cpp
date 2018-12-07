#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

/** 이동하기 백준_11048 (https://www.acmicpc.net/problem/11048)
 *  ? 반례를 찾자 -> 예제는 다 맞으나, 정답이 아님
 */

int dp[1001][1001];
int dir[3][2] = {{-1, 0}, {0, -1}, {-1, -1}};

int solution(int **arr, int n, int m)
{
    // y좌표
    for (int i = 2; i <= n; i++)
    {
        // x좌표
        for (int j = 2; j <= m; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int nxt_y = i + dir[k][0];
                int nxt_x = j + dir[k][1];
                if (nxt_y >= 1 && nxt_y <= n && nxt_x >= 1 && nxt_x <= m)
                {
                    dp[i][j] = max(arr[i][j] + dp[nxt_y][nxt_x], dp[i][j]);
                }
            }
        }
    }

    return dp[n][m];
}

int main(int argc, char const *argv[])
{
    string str = "3 4 1 2 3 4 0 0 0 5 9 8 7 6";     //31
    string str2 = "3 3 1 0 0 0 1 0 0 0 1";          //3
    string str3 = "4 3 1 2 3 6 5 4 7 8 9 12 11 10"; //47
    stringstream ss;
    ss.str(str2);

    int n, m;
    ss >> n >> m;

    int **arr = new int *[n + 1];
    for (int i = 1; i <= n; i++)
    {
        arr[i] = new int[m + 1];
        for (int j = 1; j <= m; j++)
        {
            int tmp;
            ss >> tmp;
            arr[i][j] = tmp;
        }
    }

    dp[1][1] = arr[1][1];

    for (int i = 2; i <= n; i++)
    {
        dp[i][1] = max(dp[i][1], dp[i - 1][1] + arr[i][1]);
        dp[1][i] = max(dp[1][i], dp[1][i - 1] + arr[1][i]);
    }

    cout << solution(arr, n, m) << endl;

    return 0;
}