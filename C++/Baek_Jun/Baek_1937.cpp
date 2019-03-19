#include <iostream>

/** 욕심쟁이 판다 백준_1937 ( https://www.acmicpc.net/problem/1937 )
 *  * 전체를 탐색하며 dfs를 이용
 *  REVIEW
 *  ! 재귀를 이용한 DFS와 stack을 이용한 DFS를 다시 한번 정리하자
 */

using namespace std;

int N, dp[501][501], dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int max(int &a, int &b)
{
    return a > b ? a : b;
}

int dfs(int **arr, int y, int x)
{
    // 좌표가 N x N 좌표를 넘어갔을 때는 엘리먼트가 0 ==> 더이상 탐색을 안해도 된다 ==> 넘어가기 이전에 탐색했던 곳이 첫 시작점
    if (dp[y][x])
        return dp[y][x];

    dp[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nxt_y = y + dir[i][0], nxt_x = x + dir[i][1];
        if (nxt_y > 0 && nxt_x > 0 && nxt_y <= N && nxt_x <= N)
            if (arr[y][x] < arr[nxt_y][nxt_x])
            {
                dp[y][x] = max(dp[y][x], dfs(arr, nxt_y, nxt_x) + 1);
            }
    }

    return dp[y][x];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> N;

    int **arr = new int *[N + 1];
    for (int i = 1; i <= N; i++)
    {
        arr[i] = new int[N + 1];
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            answer = max(answer, dfs(arr, i, j));
        }

    cout << answer << endl;

    return 0;
}