#include <algorithm>
#include <chrono>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int n, t, res;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int>> cheese(100, vector<int>(100, 0));

int max(int &a, int &b) { return a > b ? a : b; }

// calculate a block of cheese
int calc(int taste)
{
    int ret = 0;

    vector<vector<bool>> visit(n, vector<bool>(n, false));

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

// dp + dfs
void calc2(int cury, int curx, int taste)
{
    for(int i = 0 ; i < 4; i++)
    {
        int ny = dir[i][0] + cury;
        int nx = dir[i][1] + curx;

        if(cheese[ny][nx] > taste && !visit[ny][nx])
            calc2(ny,nx,taste);
    }
}

int solution(vector<int> &tasty)
{
    int ans = 0;

    sort(tasty.begin(), tasty.end());
    auto itr2 = unique(tasty.begin(), tasty.end());
    // the range of taste of cheese
    for (auto itr = tasty.begin(); itr != itr2; itr++)
        ans = max(ans, calc(*itr));

    return ans;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        chrono::system_clock::time_point start = chrono::system_clock::now();

        scanf("%d", &n);
        vector<int> tasty;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                cheese[i][j] = tmp;

                tasty.push_back(tmp);
            }
        }

        printf("#%d %d\n", tc, solution(tasty));

        std::cout << chrono::duration<double>(chrono::system_clock::now() - start).count() << " sec" << endl;
    }

    return 0;
}