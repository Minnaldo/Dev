#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, t, maxT, minT;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int max(int &a, int &b) { return a > b ? a : b; }
int min(int &a, int &b) { return a < b ? a : b; }

// calculate a block of cheese
int calc(vector<vector<int>> cheese, vector<vector<bool>> cpy)
{
    int ret = 0;
    auto visit = cpy;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // bfs start
            if (!visit[i][j] && cheese[i][j] != 0)
            {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                visit[i][j] = true;

                while (!q.empty())
                {
                    int cury = q.front().first;
                    int curx = q.front().second;

                    for (int k = 0; k < 4; k++)
                    {
                        int ny = dir[k][0] + cury;
                        int nx = dir[k][1] + curx;

                        if (ny >= 0 && nx >= 0 && ny < n && nx < n)
                        {
                            if (!visit[ny][nx] && cheese[ny][nx] > 0)
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

int solution(vector<vector<int>> cheese, vector<vector<bool>> visit)
{
    int ans = 0;

    // the range of taste of cheese
    for (int a = minT; a <= maxT; a++)
    {
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // The pairy eats the Cheese that is tasty level 'a'
                if (cheese[i][j] == a)
                {
                    cheese[i][j] = 0;
                    visit[i][j] = true;
                    flag = true;
                }
            }
        }

        // if (flag)
        ans = max(ans, calc(cheese, visit));
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n;
        maxT = 0;
        minT = 101;

        vector<vector<int>> cheese(n, vector<int>(n));
        vector<vector<bool>> visit(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> cheese[i][j];
                maxT = max(maxT, cheese[i][j]);
                minT = min(minT, cheese[i][j]);
            }
        }

        cout << "#" << tc << " " << solution(cheese, visit) << endl;
    }
    return 0;
}