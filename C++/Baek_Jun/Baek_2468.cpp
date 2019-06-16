#include <algorithm>
#include <iostream>
#include <vector>

/** 백준 안전영역 ( https://www.acmicpc.net/problem/2468 )
 *  * 영역 탐색시 BFS가 아닌 DFS로 구현하였더니 AC 왜??
 */

using namespace std;

int n, t, maxT;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int>> cheese(102, vector<int>(102, 0));
vector<vector<bool>> visit(102, vector<bool>(102, false));

void dfs(int y, int x, int taste)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];

        if (cheese[ny][nx] > taste && !visit[ny][nx])
        {
            if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
            {
                visit[ny][nx] = true;
                dfs(ny, nx, taste);
            }
        }
    }
}

int solution()
{
    int ans = 1;

    for (int a = 1; a < maxT; a++)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cheese[i][j] > a && !visit[i][j])
                {
                    visit[i][j] = true;
                    dfs(i, j, a);
                    cnt++;
                }
            }
        }

        ans = ans < cnt ? cnt : ans;

        for (int i = 1; i <= n; i++)
            fill_n(visit[i].begin() + 1, n + 1, false);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            cheese[i][j] = tmp;

            maxT = maxT > tmp ? maxT : tmp;
        }
    }

    printf("%d\n", solution());

    return 0;
}