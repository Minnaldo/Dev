#include <fstream>
#include <iostream>

/** 내리막길 백준_1520 ( https://www.acmicpc.net/problem/1520 )
 *  * DFS + DP
 *  * solution에서 중간에 for문으로 인해 분기가 되는 구간에서도 중첩이 되기에 0으로 초기화 가능
 *  NOTE DFS + DP
 */

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dp[501][501];
int N, M;

int solution(int **arr, int y, int x)
{
    if (y == M && x == N)
    {
        return 1;
    }

    if (dp[y][x] == -1)
    {
        dp[y][x] = 0;   // 길이 없으면 0을 리턴하게 된다
        for (int i = 0; i < 4; i++)
        {
            int nxt_y = y + dir[i][0];
            int nxt_x = x + dir[i][1];

            if (nxt_y > 0 && nxt_y <= M && nxt_x > 0 && nxt_x <= N)
            {
                if (arr[y][x] > arr[nxt_y][nxt_x])
                {
                    dp[y][x] += solution(arr, nxt_y, nxt_x);
                }
            }
        }
    }
    return dp[y][x];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    fstream fs("input.txt");

    fs >> M >> N;

    int **arr = new int *[M + 1];
    for (int i = 1; i <= M; i++)
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