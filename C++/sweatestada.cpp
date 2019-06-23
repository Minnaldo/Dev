#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t, r, c;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> map(20, vector<int>(20, 0));
vector<vector<bool>> visit(20, vector<bool>(20, false));

int dfs(int cury, int curx, vector<int> special)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = cury + dir[i][0];
        int nx = curx + dir[i][1];

        if (ny >= 0 && ny < r && nx >= 0 && nx < c)
        {
            // find to map ==> 시간 단축 방법 중 하나 일 듯
            if (!visit[ny][nx] && find(special.begin(), special.end(), map[ny][nx]) == special.end())
            {
                visit[ny][nx] = true;
                special.push_back(map[ny][nx]);
                dfs(ny, nx, special);
            }
        }
    }

    return special.size();
}

int solution()
{
    int ans = 0;
    vector<int> special;
    //special.reserve(r * c);
    special.push_back(map[0][0]);
    visit[0][0] = true;

    int tmp = dfs(0, 0, special);

    ans = ans > tmp ? ans : tmp;

    return ans;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);

    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d %d", &r, &c);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                char tmp;
                scanf("%c", &tmp);
                map[i][j] = tmp - 'A' + 1; // A : 1 ~ Z : 26
            }
        }

        printf("#%d %d\n", tc, solution());

        for (int i = 0; i < r; i++)
            fill_n(visit[i].begin(), c, false);
    }
    return 0;
}