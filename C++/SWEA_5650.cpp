#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int arr[102][102] = {5};
int n;

struct wormhole
{
    int x = 0, y = 0;
};

vector<pair<wormhole, wormhole>> portal(5);

// 방향 바뀌는 경우 방향 리턴
int attachBlock(int block, int direction)
{
    int tmp;
    switch (block)
    {
    case 1:
        tmp = (direction == 1 ? 3 : (direction == 2 ? 4 : (direction == 3 ? 2 : 1)));
        break;
    case 2:
        tmp = (direction == 1 ? 2 : (direction == 2 ? 4 : (direction == 3 ? 1 : 3)));
        break;
    case 3:
        tmp = (direction == 1 ? 4 : (direction == 2 ? 3 : (direction == 3 ? 1 : 2)));
        break;
    case 4:
        tmp = (direction == 1 ? 3 : (direction == 2 ? 1 : (direction == 3 ? 4 : 2)));
        break;
    case 5:
        tmp = direction + 2 >= 5 ? direction - 2 : direction + 2; // 반대방향으로 빠져나가는 경우
        break;
    }

    return tmp;
}

int setNY(int direction, int cury)
{
    int tmp;
    switch (direction)
    {
    case 1:
        tmp = cury--;
        break;
    case 3:
        tmp = cury++;
        break;
    default:
        tmp = cury;
    }
    return tmp;
}
int setNX(int direction, int curx)
{
    int tmp;
    switch (direction)
    {
    case 2:
        tmp = curx++;
        break;
    case 4:
        tmp = curx--;
        break;
    default:
        tmp = curx;
        break;
    }
    return tmp;
}

int run(int y, int x, int direction, int point) // 출발지점 좌표
{
    int startX = x, startY = y;
    int nx = setNX(direction, x), ny = setNY(direction, y), ndirection = direction;

    while (true)
    {
        if (arr[ny][nx] == -1 || arr[startX][startY] == arr[ny][nx]) // 블랙홀 or 시작점 일 때, 프로그램 종료
        {
            return point;
        }
        else
        {
            // 포인트를 획득해야 할 때, 벽돌 or 끝 벽
            if ((arr[ny][nx] >= 1 && arr[ny][nx] <= 5) /*|| (ny == 0 || nx == 0 || ny == n + 1 || nx == n + 1)*/)
            {
                point++;
                ndirection = attachBlock(arr[ny][nx], ndirection);      // 블록 or 벽에 부딪힌 후의 방향 리턴
                nx = setNX(ndirection, nx), ny = setNY(ndirection, ny); // 변경된 방향의 좌표
            }
            else if (arr[ny][nx] >= 6 && arr[ny][nx] <= 10) // 웜홀 일 때, 위치만 바뀜
            {
                ny = (portal[arr[ny][nx]].first.y == ny ? portal[arr[ny][nx]].second.y : portal[arr[ny][nx]].first.y);
                nx = (portal[arr[ny][nx]].first.x == nx ? portal[arr[ny][nx]].second.x : portal[arr[ny][nx]].first.x);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    int t;
    // scanf("%d", &t);
    fs >> t;

    for (int a = 1; a <= t; a++)
    {
        // scanf("%d", &n);
        fs >> n;
        int ans = 0;

        for (int i = 0; i < 102; i++)
            fill_n(arr[i], 102, 5);

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

        // for (int i = 0; i <= n + 1; i++)
        // {
        //     for (int j = 0; j <= n + 1; j++)
        //     {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (arr[i][j] == 0)
                    for (int d = 1; d <= 4; d++)
                        ans = max(ans, run(i, j, d, 0));

        printf("#%d %d\n", a, ans);
    }
    return 0;
}