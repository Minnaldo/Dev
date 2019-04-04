#include <iostream>

using namespace std;

int arr[102][102];
int n;
wormhole portal[5];

struct wormhole
{
    int x, y;
    int nx, ny;
};

// 벽에 부딪히거나
int attachBlock(int block, int direction)
{
    switch (block)
    {
    case 1:
        return (direction == 1 ? 3 : (direction == 2 ? 4 : (direction == 3 ? 2 : 1)));
        break;
    case 2:
        return (direction == 1 ? 2 : (direction == 2 ? 4 : (direction == 3 ? 1 : 3)));
        break;
    case 3:
        return (direction == 1 ? 4 : (direction == 2 ? 3 : (direction == 3 ? 1 : 2)));
        break;
    case 4:
        return (direction == 1 ? 3 : (direction == 2 ? 1 : (direction == 3 ? 4 : 2)));
        break;
    case 5:
        return direction + 2 >= 5 ? direction - 2 : direction + 2; // 반대방향으로 빠져나가는 경우
        break;
    }
}

int run(int y, int x, int direction) // 출발지점 좌표
{
    int point = 0;
    int nx = x, ny = y;

    switch (direction)
    {
    case 1:
        ny--;
        break;
    case 2:
        nx++;
        break;
    case 3:
        ny++;
        break;
    case 4:
        nx--;
        break;
    }

    while (true)
    {
        // 포인트를 획득해야 할 때, 벽돌 or 끝 벽
        if ((arr[ny][nx] >= 1 && arr[ny][nx]) <= 5 || (ny == 0 || nx == 0 || ny == n + 1 || nx == n + 1))
        {
            point++;
            continue;
        }

        if (arr[ny][nx] >= 6 && arr[ny][nx] <= 10) // 웜홀 일 때, 점수 없이 위치만 바뀜
        {
            ny = (portal[arr[ny][nx]].y == ny ? portal[arr[ny][nx]].ny : portal[arr[ny][nx]].y);
            nx = (portal[arr[ny][nx]].y == nx ? portal[arr[ny][nx]].nx : portal[arr[ny][nx]].x);
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
    int t;
    scanf("%d", &t);

    for (int a = 1; a <= t; a++)
    {

        scanf("%d", &n);
        int ans = 0;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &arr[i][j]);
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