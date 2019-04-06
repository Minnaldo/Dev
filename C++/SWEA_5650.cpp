#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct wormhole
{
    int x = 0, y = 0;
};

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int arr[102][102] = {5};
int n;
// wormhole portal[5];
vector<pair<wormhole, wormhole>> portal(5);

// 벽에 부딪히거나
int attachBlock(int block, int direction)
{
    int tmp;
    switch (block)
    {
    case 1:
        return (direction == 1 ? 3 : (direction == 2 ? 4 : (direction == 3 ? 2 : 1)));
    case 2:
        return (direction == 1 ? 2 : (direction == 2 ? 4 : (direction == 3 ? 1 : 3)));
    case 3:
        return (direction == 1 ? 4 : (direction == 2 ? 3 : (direction == 3 ? 1 : 2)));
    case 4:
        return (direction == 1 ? 3 : (direction == 2 ? 1 : (direction == 3 ? 4 : 2)));
    case 5:
        return direction + 2 >= 5 ? direction - 2 : direction + 2; // 반대방향으로 빠져나가는 경우
    default:
        return direction;
    }

    return tmp;
}

int setNY(int direction, int cury)
{
    if (direction == 1)
        cury -= 1;
    else if (direction == 3)
        cury += 1;

    return cury;
}
int setNX(int direction, int curx)
{
    if (direction == 2)
        curx += 1;
    else if (direction == 4)
        curx -= 1;

    return curx;
}

int run(int startY, int startX, int direction, int point) // 출발지점 좌표
{
    int ndirection = direction;
    int nx = setNX(direction, startX), ny = setNY(direction, startY);

    while (true)
    {
        if ((nx == startX && ny == startY) || arr[ny][nx] == -1) // 블랙홀 or 시작점
        {
            point++;
            direction = attachBlock(arr[ny][nx], direction);
            ny = dir[direction - 1][0];
            nx = dir[direction - 1][1];
            continue;
        }
        else if (arr[ny][nx] == 5)
        {
            ny = (portal[arr[ny][nx]].first.y == ny ? portal[arr[ny][nx]].second.y : portal[arr[ny][nx]].first.y);
            nx = (portal[arr[ny][nx]].first.x == nx ? portal[arr[ny][nx]].second.x : portal[arr[ny][nx]].first.x);
            continue;
        }
        else if (arr[ny][nx] != 0) // 웜홀과 벽
        {
            // 포인트를 획득해야 할 때, 벽돌 or 끝 벽
            if ((arr[ny][nx] >= 1 && arr[ny][nx] <= 4) /*|| (ny == 0 || nx == 0 || ny == n + 1 || nx == n + 1)*/)
            {
                point++;
                ndirection = attachBlock(arr[ny][nx], ndirection);      // 블록 or 벽에 부딪힌 후의 방향 리턴
                nx = setNX(ndirection, nx), ny = setNY(ndirection, ny); // 변경된 방향의 좌표
            }
            else if (6 <= arr[ny][nx] && arr[ny][nx] <= 10) // 웜홀 일 때, 위치만 바뀜
            {
                int idx = arr[ny][nx] - 6;
                if (portal[idx].first.x != 0)
                    if (portal[idx].first.x == nx && portal[idx].first.y == ny)
                    {
                        nx = portal[idx].second.x;
                        ny = portal[idx].second.y;
                    }
                    else
                    {
                        nx = portal[idx].first.x;
                        ny = portal[idx].first.y;
                    }
            }
            continue;
        }

        nx = setNX(ndirection, nx);
        ny = setNY(ndirection, ny);
    } // end of while
}

// int run_recur(int y, int x, int direction, int starty, int startx, int point)
// {
//     int ny, nx, ndirection;
//     if ((y == starty && x == startx) || arr[y][x] == -1)
//     {
//         return point;
//     }
//     else if (arr[y][x] >= 6 && arr[y][x] <= 10) // 웜홀 일 때
//     {
//         if (portal[arr[y][x]])
//         {
//         }
//         else
//         {
//         }
//     }

//     run_recur(ny, nx, ndirection, starty, startx, point);
// }

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    int t;
    fs >> t;
    // scanf("%d", &t);

    for (int a = 1; a <= t; a++)
    {

        // scanf("%d", &n);
        fs >> n;
        int ans = 0;

        for (int i = 0; i < 102; i++)
            fill_n(arr[i], 102, 5); // 끝벽을 5로 만들기 위해

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                // scanf("%d", &arr[i][j]);
                fs >> arr[i][j];
                if (arr[i][j] >= 6 && arr[i][j] <= 10) // 웜홀일 때
                {
                    if (portal[arr[i][j] - 6].first.y == 0)
                    {
                        portal[arr[i][j] - 6].first.y = i;
                        portal[arr[i][j] - 6].first.x = j;
                    }
                    else
                    {
                        portal[arr[i][j] - 6].second.y = i;
                        portal[arr[i][j] - 6].second.x = j;
                    }
                }
            }

        // for (int q = 0; q < portal.size(); q++)
        // {
        //     cout << portal[q].first.y << " " << portal[q].first.x << "   :::   " << portal[q].second.y << " " << portal[q].second.x << endl;
        // }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (arr[i][j] == 0)              // 비어있는 블록에서만 출발 가능
                    for (int d = 1; d <= 4; d++) // 비어있는 블록에서 출발 시, 4방향으로 출발
                        ans = max(ans, run(i, j, d, 0));

        printf("#%d %d\n", a, ans);
    }
    return 0;
}