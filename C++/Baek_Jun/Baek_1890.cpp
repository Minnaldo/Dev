#include <fstream>
#include <iostream>

/** 점프 백준_1890 ( https://www.acmicpc.net/problem/1890 )
 *  * DFS + DP
 *  * solution에서 중간에 for문으로 인해 분기가 되는 구간에서도 중첩이 되기에 0으로 초기화 가능
 *  * 경로의 개수가 2^63 - 1 개 보다 작으므로, 반환형을 이보다 큰 long long형을 써서 리턴
 *  REVIEW
 */

using namespace std;

int dir[4][2] = {{1, 0}, {0, 1}};
long long dp[101][101];
int N;

long long solution(int **arr, int y, int x)
{
    if (y == N && x == N)
    {
        return 1;
    }

    if (dp[y][x] == -1)
    {
        dp[y][x] = 0;
        for (int i = 0; i < 2; i++)
        {
            int nxt_y = y + (dir[i][0] * arr[y][x]);
            int nxt_x = x + (dir[i][1] * arr[y][x]);

            if (nxt_y > 0 && nxt_y <= N && nxt_x > 0 && nxt_x <= N)
            {
                dp[y][x] += solution(arr, nxt_y, nxt_x);
            }
        }
    }
    return dp[y][x];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    fstream fs("input.txt");

    fs >> N;

    int **arr = new int *[N + 1];
    for (int i = 1; i <= N; i++)
    {
        arr[i] = new int[N + 1];
        for (int j = 1; j <= N; j++)
        {
            fs >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    cout << solution(arr, 1, 1) << endl;
    return 0;
}