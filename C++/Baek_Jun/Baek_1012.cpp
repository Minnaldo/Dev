#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

/** 유기농 배추 백준_1012 ( https://www.acmicpc.net/problem/1012 )
 *  * BFS를 이용하는 문제
 */

using namespace std;

int T, m, n, k, ans;
bool visit[50][50];
int map[50][50], dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int solution(int sy, int sx)
{
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    visit[sy][sx] = true;
    int cnt = 0;

    while (!q.empty())
    {
        int curx = q.front().second;
        int cury = q.front().first;

        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dir[i][1];
            int ny = cury + dir[i][0];

            if (!visit[ny][nx] && map[ny][nx] == 1 && ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                visit[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }

        q.pop();
    }

    return 1;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &T);

    while (T--)
    {
        ans = 0;
        scanf("%d %d %d", &m, &n, &k);

        for (int i = 0; i < k; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            map[y][x] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visit[i][j] && map[i][j] == 1)
                    ans += solution(i, j);
            }
        }

        printf("%d\n", ans);
        memset(visit, false, sizeof(visit));
        memset(map, 0, sizeof(map));
    }
    return 0;
}