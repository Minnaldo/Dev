#include <algorithm>
#include <iostream>
#include <vector>

/** 격자판의 숫자 이어 붙이기 SWEA_2819 ( https://www.swexpertacademy.com/main/code/problem/problemDetail.do )
 */

using namespace std;

int t, map[4][4]; // 맵
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<int> arr; // 수를 저장할 배열

void dfs(int tmp, int y, int x, int cnt)
{
    if (cnt == 6)
    {
        arr.push_back(tmp);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];

        if (ny >= 0 && nx >= 0 && ny < 4 && nx < 4) // 격자 범위 내일 때
        {
            dfs(tmp * 10 + map[ny][nx], ny, nx, cnt + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        int ans = 0;

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                scanf("%d", &map[i][j]);

        // 루틴 시작
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                dfs(map[i][j], i, j, 0);

        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        ans = arr.size();

        printf("#%d %d\n", tc, ans);
        arr.clear();
    }
    return 0;
}