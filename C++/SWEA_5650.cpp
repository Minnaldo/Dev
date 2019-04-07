#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct wormhole
{
    int x = 0, y = 0;
};

int arr[102][102] = {5};
int n;
// wormhole portal[5];
vector<pair<wormhole, wormhole>> portal(5);

// 방향 바뀌는 경우 방향 리턴
// 반대방향으로 가게되면 11을 리턴하고 현재까지 포인트의 -1의 2배만큼을 리턴
int attachBlock(int block, int direction)
{
    switch (block) // block type
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
        return (direction == 1 || direction == 3) ? (4 - direction) : (direction == 1 ? 4 : 1); // 반대방향으로 빠져나가는 경우
    }
}

int setNY(int direction, int cury)
{
    if (direction == 1)
        return --cury;
    else if (direction == 3)
        return ++cury;
}
int setNX(int direction, int curx)
{
    if (direction == 2)
        return ++curx;
    else if (direction == 4)
        return --curx;
}

int run(int startY, int startX, int direction) // 출발지점 좌표
{
    int point = 0;
    int ndirection = direction;
    int nx = setNX(ndirection, startX), ny = setNY(ndirection, startY);

    while (true)
    {
        if (arr[ny][nx] == 0)
        {
            if (ny == startY && nx == startX) // 시작점, 현재까지의 점수를 반환한다.
            {
                return point;
            }
            else // 시작점 이외 아무것도 없는 블록, 방향 변화 없음
            {
                nx = setNX(ndirection, nx);
                ny = setNY(ndirection, ny);
            }
        }
        else
        {
            if (arr[ny][nx] == -1) // 블랙홀, 현재까지 점수를 반환한다
            {
                return point;
            }
            else if (1 <= arr[ny][nx] && arr[ny][nx] <= 5) // 블록
            {
                point++;
                ndirection = attachBlock(arr[ny][nx], ndirection); // 다음 블록 타입, 현재 진행 방향
                // 바뀐 방향에 따른 다음 블록의 좌표
                ny = setNY(ndirection, ny);
                nx = setNX(ndirection, nx);
            }
            else if (6 <= arr[ny][nx] && arr[ny][nx] <= 10) // 웜홀
            {
                int woreholeIdx = arr[ny][nx] - 6; // 웜홀 저장 벡터의 인덱스
                if (ny == portal[woreholeIdx].first.y && nx == portal[woreholeIdx].first.x)
                {
                    ny = portal[woreholeIdx].second.y;
                    nx = portal[woreholeIdx].second.x;
                }
                else
                {
                    ny = portal[woreholeIdx].first.y;
                    nx = portal[woreholeIdx].first.x;
                }
            }
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
                        ans = max(ans, run(i, j, d));

        printf("#%d %d\n", a, ans);
    }
    return 0;
}