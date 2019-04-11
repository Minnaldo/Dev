#include <fstream>
#include <iostream>
#include <vector>

/** TODO
 *  * 4번 케이스의 시간이 오래걸린다
 */

using namespace std;

struct wormhole
{
    int x = 0, y = 0;
};

int dir[5][2] = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 1, 2, 3, 4 순으로 이동 방향 좌표
int arr[102][102];
vector<pair<wormhole, wormhole>> portal(6);

int max(int &a, int &b) { return a > b ? a : b; }

int attachBlock(int block, int direction)
{
    switch (block) // block type
    {
    case 1:
        return direction == 3 ? 2 : (direction == 4 ? 1 : 11);
    case 2:
        return direction == 1 ? 2 : (direction == 4 ? 3 : 11);
    case 3:
        return direction == 1 ? 4 : (direction == 2 ? 3 : 11);
    case 4:
        return direction == 2 ? 1 : (direction == 3 ? 4 : 11);
    case 5:
        return 11;
    }
}

int run(int startY, int startX, int direction) // 출발지점 좌표
{
    int point = 0, ny, nx, nxtBlock;
    int ndirection = direction;
    int curx = startX, cury = startY;

    while (true)
    {
        ny = cury + dir[ndirection][0];
        nx = curx + dir[ndirection][1];
        nxtBlock = arr[ny][nx]; // 진해방향 다음칸의 블록

        if (nxtBlock == -1 || (ny == startY && nx == startX)) // 시작점, 현재까지의 점수를 반환한다.
        {
            return point;
        }
        else if (1 <= nxtBlock && nxtBlock <= 5) // 블록
        {
            point++;
            if (nxtBlock == 5)
                return (point * 2) - 1;

            ndirection = attachBlock(nxtBlock, ndirection); // 다음 블록 타입, 현재 진행 방향 => 다음 진행방향
            if (ndirection == 11)
            {
                return (point * 2) - 1;
            }
            // 바뀐 방향에 따른 다음 블록의 좌표
            curx = nx;
            cury = ny;
        }
        else if (6 <= nxtBlock && nxtBlock <= 10) // 웜홀
        {                                         // 웜홀 앞에 블록이 ( 1~5 ) 있다면?
            int woreholeIdx = nxtBlock - 6;       // 웜홀 저장 벡터의 인덱스
            if (ny == portal[woreholeIdx].first.y && nx == portal[woreholeIdx].first.x)
            {
                cury = portal[woreholeIdx].second.y;
                curx = portal[woreholeIdx].second.x;
            }
            else
            {
                cury = portal[woreholeIdx].first.y;
                curx = portal[woreholeIdx].first.x;
            }
        }
        else
        {
            cury = ny;
            curx = nx;
        }
    } // end of while
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    int t;
    fs >> t;
    // scanf("%d", &t);

    for (int a = 1; a <= t; a++)
    {
        int n;
        // scanf("%d", &n);
        fs >> n;
        int ans = 0;

        for (int i = 0; i <= n + 1; i++)
            arr[i][0] = arr[i][n + 1] = arr[n + 1][i] = arr[0][i] = 5;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                // scanf("%d", &arr[i][j]);
                fs >> arr[i][j];
                if (6 <= arr[i][j] && arr[i][j] <= 10) // 웜홀일 때
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

        // for (int i = 0; i < n + 2; i++)
        // {
        //     for (int j = 0; j < n + 2; j++)
        //     {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
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