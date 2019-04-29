#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 *
 */

using namespace std;

int t, map[4][4]; // 맵
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<string> arr; // 수를 저장할 배열

void dfs(string tmp, int y, int x)
{
    if (tmp.size() == 7)
    {
        arr.push_back(tmp);
    }
    else if (tmp.size() < 7)
    {
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny >= 0 && nx >= 0 && ny < 4 && nx < 4)
            {
                tmp += to_string(map[ny][nx]);
                dfs(tmp, ny, nx);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        int ans = 0;

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                scanf("%d", &map[i][j]);

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                string tmp = "";
                tmp += to_string(map[i][j]);
                dfs(tmp, i, j);
            }

        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        ans = arr.size();

        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << endl;
        }

        printf("#%d %d\n", tc, ans);
        arr.clear();
    }
    return 0;
}