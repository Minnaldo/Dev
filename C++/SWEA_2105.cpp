#include <algorithm>
#include <fstream>
#include <iostream>

/**
 *  * 한방향 으로만 도는것이 포인트! ==> 90도씩 돌려가며 푼다.
 *  * 어차피 사각형을 그리며 돌아와야 하므로 매 순간 90도씩 한방향으로 돌아가며 풀면 시간이 많이 걸리지 않는다.
 */

using namespace std;

int dir[4][2] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
int map[20][20];
int n, t, ans;
bool visit[20][20], chk[101];

int max(int &a, int &b) { return a > b ? a : b; }

void solution(int y, int x, int starty, int startx, int cnt, int rota)
{
    if (y == starty && x == startx && cnt > 0) // 종료 조건
    {
        ans = ans > cnt ? ans : cnt;
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        int ny = y + dir[rota + i][0];
        int nx = x + dir[rota + i][1];

        if (ny >= 0 && ny < n && nx >= 0 && nx < n)
        {
            if (!visit[ny][nx] && !chk[map[ny][nx]])
            {
                visit[ny][nx] = true;
                chk[map[ny][nx]] = true;
                solution(ny, nx, starty, startx, cnt + 1, rota + i);
                visit[ny][nx] = false;
                chk[map[ny][nx]] = false;
            }
            else if (ny == starty && nx == startx)
            {
                solution(ny, nx, starty, startx, cnt + 1, rota + i);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    // scanf("%d", &t);
    fs >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        ans = -1;
        // scanf("%d", &n);
        fs >> n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                // scanf("%d", &map[i][j]);
                fs >> map[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                chk[map[i][j]] = true;
                solution(i, j, i, j, 0, 0);
                chk[map[i][j]] = false;
            }

        printf("#%d %d\n", tc, ans);

        // 체크 배열들 초기화
        fill_n(chk, 101, false);
        for (int i = 0; i < n; i++)
            fill_n(visit[i], 20, false);
    }
    return 0;
}