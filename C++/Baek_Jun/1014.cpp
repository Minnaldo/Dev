#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int c, n, m, ans;
int map[10][10];
int chks[7][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 1}, {0, 1}, {1, 1}, {0, 0}};
bool visit[10][10];

int max(int &a, int &b) { return a > b ? a : b; }

void chk(int cury, int curx)
{
    // visit[cury][curx] = true;
    for (int i = 0; i < 7; i++)
    {
        int ny = cury + chks[i][0];
        int nx = curx + chks[i][1];
        if (nx >= 0 && ny >= 0 && nx < m && ny < n)
        {
            visit[ny][nx] = true;
        }
    }
}

void dfs(int cury, int curx, int cnt)
{
    chk(cury, curx);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j] && map[i][j] == 0)
            {
                dfs(i, j, cnt + 1);
            }
        }
    }
    ans = max(ans, cnt);
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < str.size(); j++)
            {
                if (str[j] == '.')
                    map[i][j] = 0;
                else
                    map[i][j] = 1;
            }
        }

        ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visit[i][j] && map[i][j] == 0)
                    dfs(i, j, 1);
                memset(visit, false, sizeof(visit));
            }
        }

        printf("%d\n", ans);

        memset(map, -1, sizeof(map));
    }
    return 0;
}