#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

/**
 *
 */

using namespace std;

int t, n, m, dx, dy, sx, sy, gy, gx, cnt;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<int>> map(50, vector<int>(50, 0));
vector<vector<bool>> visit(50, vector<bool>(50, false));
vector<vector<int>> time(50, vector<int>(50, 0));

int min(int &a, int &b) { return a < b ? a : b; }

// 수연이의 이동경로와 시간
void dfs(int cury, int curx)
{
    visit[cury][curx] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = cury + dir[i][0];
        int nx = curx + dir[i][1];

        if (ny >= 0 && nx >= 0 && ny < n && nx < m)
        {
            if (!visit[ny][nx] && map[ny][nx] >= 0)
            {
                if (time[ny][nx])
                    time[ny][nx] = min(time[ny][nx], time[cury][curx] + 1);
                else
                    time[ny][nx] = time[cury][curx] + 1;

                dfs(ny, nx);
            }
        }
    }
}

void bfs(int cury, int curx, bool flag)
{
    visit[cury][curx] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = cury + dir[i][0], nx = curx + dir[i][1];

        if (ny >= 0 && nx >= 0 && ny < n && nx < m)
        {
            if (!visit[ny][nx] && map[ny][nx] != -1)
            {
                if (ny == gy && nx == gx)
                {
                    cnt = map[cury][curx] + 1;
                }
                else
                {
                    if (flag)
                    {
                        map[ny][nx] = map[cury][curx] + 1;
                    }
                    else
                    {
                    }
                }
            }
        }
    }
}

string solution()
{
    dfs(sy, sx);
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char tmp;
                scanf("%c", &tmp);
                if (tmp == 'D')
                {
                    gy = i, gx = j;
                    map[i][j] = 0;
                }
                else if (tmp == '*')
                {
                    map[i][j] = -1;
                    visit[i][j] = true;
                    dy = i, dx = j;
                }
                else if (tmp == 'S')
                {
                    map[i][j] = -6;
                    sy = i, sx = j;
                }
                else if (tmp == 'X')
                {
                    visit[i][j] = true;
                    map[i][j] = -7;
                }
            }
        }

        cout << "#" << tc << " " << solution() << "\n";
    }
    return 0;
}