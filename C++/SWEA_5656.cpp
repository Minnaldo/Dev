#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>

/**
 *! https://organize-study.tistory.com/167  다시 짠다
 */

using namespace std;

int map[12][15], w, h, visit[12][15];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(int n, int y, int x, int mul)
{
    int ans = 0;
    if (n == 0)
    {
        // 깨진 벽돌의 개수 리턴
        int tmpsum = 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (visit[i][j] == -1)
                    tmpsum++;
        return tmpsum;
    }

    // 깬 벽돌을 표시해야 한다.
    if (mul > 1)
    {
        for (int i = y - (mul - 1); i <= y + (mul - 1); i++)
        {
            int tmp = map[i][x];
            visit[i][x] = -1;
            dfs(n, i, x, tmp);
        }
        for (int i = x - (mul - 1); i <= x + (mul - 1); i++)
        {
            int tmp = map[y][i];
            visit[y][i] = -1;
            dfs(n, y, i, tmp);
        }
    }
    else // 1인 칸을 지웠을 경우 다음 구슬을 사용한다
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                if (map[j][i] != 0)
                {
                    // 블록깨기 실행 ( dfs )
                    int tmp = map[j][i];
                    if (tmp == 1)
                    {                     // 블록에 쓰인 숫자가 1이면 하나만 깨지고 끝
                        visit[j][i] = -1; // 깨진 벽돌 표시
                        dfs(n - 1, w, h, 1);
                    }
                    else
                    {
                        for (int j = 0; j < tmp; j++)
                            for (int i = 0; i < 4; i++)
                            {
                                int ny = j * dir[i][0];
                                int nx = j * dir[i][1];
                                visit[ny][nx] = -1;
                                dfs(n - 1, ny, nx, tmp);
                            }
                    }
                }
            }
        }
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    int T;
    // scanf("%d", &T);
    fs >> T;

    for (int i = 1; i <= T; i++)
    {
        int n, bSum = 0, maxBreak = 0;

        // scanf("%d %d %d", &n, &w, &h);
        fs >> n >> w >> h;

        for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++)
            {
                // scanf("%d", &map[i][j]);
                fs >> map[i][j];
                bSum++;
            }

        for (int j = 0; j < w; j++)
            for (int i = 0; i < h; i++)
                if (map[i][j] != 0 && map[i - 1][j] == 0)
                {
                    maxBreak = max(maxBreak, dfs(n, i, j, map[i][j]));
                    for (int k = 0; k < h; k++)
                        memset(visit[k], 0, sizeof(int) * 15);
                }

        printf("#%d %d\n", i, bSum - maxBreak);
    }
    return 0;
}