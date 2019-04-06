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
}

int run(int y, int x, int direction) // 출발지점 좌표
{
    int point = 0;
    int nx = x, ny = y;

    // switch (direction)
    // {
    // case 1:
    //     ny--;
    //     break;
    // case 2:
    //     nx++;
    //     break;
    // case 3:
    //     ny++;
    //     break;
    // case 4:
    //     nx--;
    //     break;
    // }

    while (true)
    {
        // 포인트를 획득해야 할 때, 벽돌 or 끝 벽
        if ((arr[ny][nx] >= 1 && arr[ny][nx]) <= 5 || (ny == 0 || nx == 0 || ny == n + 1 || nx == n + 1))
        {
            point++;
            direction = attachBlock(arr[ny][nx], direction);
            ny = dir[direction - 1][0];
            nx = dir[direction - 1][1];
            continue;
        }

        if (arr[ny][nx] >= 6 && arr[ny][nx] <= 10) // 웜홀 일 때, 점수 없이 위치만 바뀜
        {
            ny = (portal[arr[ny][nx]].first.y == ny ? portal[arr[ny][nx]].second.y : portal[arr[ny][nx]].first.y);
            nx = (portal[arr[ny][nx]].first.x == nx ? portal[arr[ny][nx]].second.x : portal[arr[ny][nx]].first.x);
            continue;
        }

        if (arr[ny][nx] == -1 || arr[ny][nx] == arr[y][x]) // 블랙홀 or 시작점 일 때, 프로그램 종료
        {
            return point;
        }
    }
}

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

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                // scanf("%d", &arr[i][j]);
                fs >> arr[i][j];
                // 웜홀 쌍 입력
                if (arr[i][j] >= 6 && arr[i][j] <= 10)
                {
                    if (portal[arr[i][j] - 6].second.y != 0)
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

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (arr[i][j] == 0)
                    for (int s = 1; s <= 4; s++)
                        ans = max(ans, run(i, j, s));

        printf("#%d %d\n", a, ans);
    }
    return 0;
}