#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct AirFresher
{
    int y1 = 0, y2 = 0;
};

queue<pair<int, int>> dust;
int t, ans, w, h, s;
int map[40][40], cpy[40][40];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
AirFresher af;

int findDirection(int y, int x, int afy)
{
    if (x == 0)
    {
        if (y == 0 || y == h - 1)
        {
            return 2;
        }

        if (y < afy)
        {
            return 1;
        }
        else if (y > afy)
        {
            return 3;
        }
    }
    else if (x == w - 1)
    {
        if (y == afy)
        {
            return 4;
        }

        if (y <= afy)
        {
            return 3;
        }
        else if (y >= afy)
        {
            return 1;
        }
    }
    else
    {
        if (y == 0 || y == h - 1)
        {
            return 2;
        }
        else
        {
            return 4;
        }
    }
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void cpytToMap()
{
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (cpy[i][j] > 0)
                map[i][j] += cpy[i][j];
}

void dustExpand(int y, int x)
{
    if (map[y][x] == -1)
        return;

    int exDust = map[y][x] / 5;
    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];

        if (map[ny][nx] >= 0 && ny >= 0 && ny < h && nx >= 0 && nx < w)
        {
            cpy[ny][nx] += exDust;
            cnt++;
        }
    }

    map[y][x] -= (cnt * exDust);
}

void makeQueue()
{
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (map[i][j] > 0)
                dust.push(make_pair(i, j));
}

void afoperation()
{
    int y = af.y1 - 1;
    int x = 0;
    while (true)
    {
        int direction = findDirection(y, x, af.y1) - 1;
        int ny = y + dir[direction][0];
        int nx = x + dir[direction][1];

        if (map[ny][nx] == -1)
            break;
        if (ny >= 0 && nx >= 0 && ny < h && nx < w)
        {
            swap(map[y][x], map[ny][nx]);

            y = ny;
            x = nx;
        }
    }

    y = af.y2 + 1;
    x = 0;
    while (true)
    {
        int direction = findDirection(y, x, af.y1) - 1;
        int ny = y + dir[direction][0];
        int nx = x + dir[direction][1];

        if (map[ny][nx] == -1)
            break;
        if (ny >= 0 && nx >= 0 && ny < h && nx < w)
        {
            swap(map[y][x], map[ny][nx]);

            y = ny;
            x = nx;
        }
    }

    map[af.y1][1] = map[af.y2][1] = 0;
}

int clac()
{
    int cnt = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (map[i][j] > 0)
                cnt += map[i][j];
        }
    }

    return cnt;
}

void solution()
{
    for (int i = 0; i < s; i++)
    {
        // expand
        while (!dust.empty())
        {
            dustExpand(dust.front().first, dust.front().second);
            dust.pop();
        }
        cpytToMap();
        afoperation(); // operate AirFresher

        memset(cpy, 0, sizeof(cpy)); // temporary 2d array initialize
        makeQueue();
    }
}

int main(int argc, char const *argv[])
{
    freopen("test_input.txt", "r", stdin); // 파일에서 내용을 읽어 표준입출력으로 전송
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d %d %d", &w, &h, &s);
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                scanf("%d", &map[i][j]);
                if (map[i][j] > 0)
                {
                    dust.push(make_pair(i, j));
                }
                if (map[i][j] < 0)
                {
                    if (af.y1 == 0)
                        af.y1 = i;
                    else
                        af.y2 = i;
                }
            }
        }
        solution();
        ans = clac();
        printf("#%d %d\n", tc, ans);
    }

    return 0;
}