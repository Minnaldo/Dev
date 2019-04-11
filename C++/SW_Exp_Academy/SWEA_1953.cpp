#include <algorithm>
#include <iostream>
#include <queue>

/**
 *  * func 함수를 바꿀 수 있지 않을까?
 */

using namespace std;

int map[50][50], visit[50][50];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 1, 2, 3, 4

bool func(int direction, int curPipe, int nPipe)
{
    switch (curPipe)
    {
    case 1:
        if (direction == 1)
            return nPipe == 1 ? true : (nPipe == 2 ? true : (nPipe == 5 ? true : (nPipe == 6 ? true : false)));
        else if (direction == 2)
            return nPipe == 1 ? true : (nPipe == 3 ? true : (nPipe == 6 ? true : (nPipe == 7 ? true : false)));
        else if (direction == 3)
            return nPipe == 1 ? true : (nPipe == 2 ? true : (nPipe == 4 ? true : (nPipe == 7 ? true : false)));
        else
            return nPipe == 1 ? true : (nPipe == 3 ? true : (nPipe == 4 ? true : (nPipe == 5 ? true : false)));
        break;
    case 2:
        if (direction == 1)
            return nPipe == 1 ? true : (nPipe == 2 ? true : (nPipe == 5 ? true : (nPipe == 6 ? true : false)));
        else if (direction == 3)
            return nPipe == 1 ? true : (nPipe == 2 ? true : (nPipe == 4 ? true : (nPipe == 7 ? true : false)));
        break;
    case 3:
        if (direction == 2)
            return nPipe == 1 ? true : (nPipe == 3 ? true : (nPipe == 6 ? true : (nPipe == 7 ? true : false)));
        else if (direction == 4)
            return nPipe == 1 ? true : (nPipe == 3 ? true : (nPipe == 4 ? true : (nPipe == 5 ? true : false)));
        break;
    case 4:
        if (direction == 1)
            return nPipe == 1 ? true : (nPipe == 2 ? true : (nPipe == 5 ? true : (nPipe == 6 ? true : false)));
        else if (direction == 2)
            return nPipe == 1 ? true : (nPipe == 3 ? true : (nPipe == 6 ? true : (nPipe == 7 ? true : false)));
        break;
    case 5:
        if (direction == 2)
            return nPipe == 1 ? true : (nPipe == 3 ? true : (nPipe == 6 ? true : (nPipe == 7 ? true : false)));
        else if (direction == 3)
            return nPipe == 1 ? true : (nPipe == 2 ? true : (nPipe == 4 ? true : (nPipe == 7 ? true : false)));
        break;
    case 6:
        if (direction == 3)
            return nPipe == 1 ? true : (nPipe == 2 ? true : (nPipe == 4 ? true : (nPipe == 7 ? true : false)));
        else if (direction == 4)
            return nPipe == 1 ? true : (nPipe == 3 ? true : (nPipe == 4 ? true : (nPipe == 5 ? true : false)));
        break;
    case 7:
        if (direction == 1)
            return nPipe == 1 ? true : (nPipe == 2 ? true : (nPipe == 5 ? true : (nPipe == 6 ? true : false)));
        else if (direction == 4)
            return nPipe == 1 ? true : (nPipe == 3 ? true : (nPipe == 4 ? true : (nPipe == 5 ? true : false)));
        break;
    }
    return false;
}

int solution(int y, int x, int n, int m, int l)
{
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    visit[y][x] = 1;
    int cnt = 1;

    while (!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;

        for (int i = 0; i < 4; i++)
        {
            int ny = cury + dir[i][0];
            int nx = curx + dir[i][1];

            if (visit[ny][nx] == 0 && (ny >= 0 && ny < n && nx >= 0 && nx < m))
            {
                if (map[ny][nx] != 0 && func(i + 1, map[cury][curx], map[ny][nx]))
                {
                    q.push(make_pair(ny, nx));
                    visit[ny][nx] = visit[cury][curx] + 1;
                    if (visit[ny][nx] > 0 && visit[ny][nx] <= l)
                        cnt++;
                }
            }
        }
        q.pop();
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        int ans = 0;
        int n, m, r, c, l;
        scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &map[i][j]);

        ans = solution(r, c, n, m, l);

        for (int i = 0; i < 50; i++)
            fill_n(visit[i], 50, 0);

        printf("#%d %d\n", tc, ans);
    }
    return 0;
}