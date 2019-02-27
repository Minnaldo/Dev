#include <fstream>
#include <iostream>
#include <queue>
#include <string>

/** 가장 큰 정사각형 백준_1915 ( https://www.acmicpc.net/problem/1915 )
 *  * way 1) 가로 세로 크기만 구해서 곱한다.
 *  * way 2) 확실한 크기를 구한다
 *  * DP + DFS?? / DP + BFS?
 */

using namespace std;

int N, M;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dp[1001][1001];

int max(int &a, int &b) { return a > b ? a : b; }

// TODO how to search for square in 2-dimetion array
int solution(int **arr, int y, int x)
{
    int tmp = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    dp[y][x] = 1;

    while (!q.empty())
    {
        y = q.front().first, x = q.front().second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][1], ny = y + dir[i][0];

            if (ny > 0 && nx > 0 && ny <= M && nx <= N)
            {
                if (arr[ny][nx] == 1)
                {
                    q.push(make_pair(ny, nx));
                    dp[ny][nx] = dp[y][x] + 1;
                }
            }
        }

        q.pop();
    }

    return dp[y][x];
}

int dfs(int **arr, int y, int x){
    if(dp[y][x]) return dp[y][x];

    dp[y][x] = 1;

    for(int i = 0; i<4; i++)
    {
        int nx = x + dir[i][1], ny = y + dir[i][0];
        if (ny > 0 && nx > 0 && ny <= M && nx <= N)
        if(arr[ny][nx] == 1)
        {
            dp[y][x] = max(dp[y][x], dfs(arr, ny, nx)+1);
        }
    }

    return dp[y][x];
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    ios::sync_with_stdio(false);
    cin.tie();

    fs >> N >> M;

    string str = "";

    int **arr = new int *[N + 1];
    for (int i = 1; i <= N; i++)
    {
        arr[i] = new int[M + 1];
        fs >> str;
        for (int j = 0; j < M; j++)
        {
            arr[i][j + 1] = str[j] - '0';
        }
    }

    int answer = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (arr[i][j] == 1)
                // answer = max(answer, solution(arr, i, j));
                answer = max(answer, dfs(arr, i, j));
        }
    }

    cout << answer << endl;
    return 0;
}