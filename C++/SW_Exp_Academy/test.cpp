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

void printMap()
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void printCpy()
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%d ", cpy[i][j]);
        }
        printf("\n");
    }
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

        while (!dust.empty())
        {
            dustExpand(dust.front().first, dust.front().second);
            dust.pop();
        }
        cpytToMap();
        printCpy();
        cout << endl
             << endl;
        printMap();

        memset(cpy, 0, sizeof(cpy));
    }

    return 0;
}