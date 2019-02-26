#include <algorithm>
#include <iostream>
#include <queue>

/**
 *  * 어디서 출발 하여 DFS를 수행할 것인가
 *  * 기본 테스트케이스 결과 = 2, but correct answer is 4
 */

using namespace std;

vector<vector<int>> vec(501, vector<int>(3));
int N, dist;
bool chk[501][501];
int map[501][501];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int max(int &a, int &b)
{
    return a > b ? a : b;
}

void solution(int **arr, int y, int x)
{
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    map[y][x] = 1;

    while (!q.empty())
    {
        int cur_y = q.front().first, cur_x = q.front().second;

        for (int i = 0; i < 4; i++)
        {
            int nxt_y = cur_y + dir[i][0], nxt_x = cur_x + dir[i][1];

            if (!chk[nxt_y][nxt_x] && nxt_y > 0 && nxt_x > 0 && nxt_y <= N && nxt_x <= N)
                if (arr[cur_y][cur_x] < arr[nxt_y][nxt_x])
                    if (map[nxt_y][nxt_x] <= map[cur_y][cur_x] + 1)
                    {
                        map[nxt_y][nxt_x] = map[cur_y][cur_x] + 1;
                        dist = max(dist, map[nxt_y][nxt_x]);
                    }
        }
        q.pop();
    }
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

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (map[i][j] < 1)
            {
                solution(arr, i, j);
            }
        }
    }

    cout << dist << endl;

    return 0;
}