#include <algorithm>
#include <chrono>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, t, minT, maxT;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int>> cheese(100, vector<int>(100, 0));
vector<vector<bool>> visit(100, vector<bool>(100, false));
int max(int &a, int &b) { return a > b ? a : b; }

// calculate a block of cheese
int calc(int taste)
{
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // bfs start
            if (cheese[i][j] > taste && !visit[i][j])
            {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                visit[i][j] = true;

                while (!q.empty())
                {
                    int cury = q.front().first, curx = q.front().second;

                    for (int k = 0; k < 4; k++)
                    {
                        int ny = dir[k][0] + cury;
                        int nx = dir[k][1] + curx;

                        if (ny >= 0 && nx >= 0 && ny < n && nx < n)
                        {
                            if (cheese[ny][nx] > taste && !visit[ny][nx])
                            {
                                q.push(make_pair(ny, nx));
                                visit[ny][nx] = true;
                            }
                        }
                    }
                    q.pop();
                }
                // bfs가 끝날때 마다 1씩 증가해 덩어리수 확인
                ret++;
            } // end of bfs
        }
    }

    return ret;
}

void dfs(int y, int x, int taste)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];

        if (ny >= 0 && nx >= 0 && ny < n && nx < n)
        {
            if (cheese[ny][nx > taste && !visit[ny][nx]])
            {
                visit[ny][nx] = true;
                dfs(ny, nx, taste);
            }
        }
    }
}

int solution()
{
    int ans = 0;

    // the range of taste of cheese
    for (int a = minT; a <= maxT; a++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cheese[i][j] > a && !visit[i][j])
                {
                    visit[i][j] = true;
                    dfs(i, j, a);
                    cout << "test" << endl;
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);

        for (int i = 0; i < n; i++)
            fill_n(visit[i].begin(), n, false);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        chrono::system_clock::time_point start = chrono::system_clock::now();

        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                cheese[i][j] = tmp;

                minT = minT < tmp ? minT : tmp;
                maxT = maxT > tmp ? maxT : tmp;
            }
        }

        printf("#%d %d\n", tc, solution());

        std::cout << chrono::duration<double>(chrono::system_clock::now() - start).count() << " sec" << endl;
    }

    return 0;
}