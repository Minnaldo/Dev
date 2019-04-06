#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cell
{
    int life = 0;
    int createTime = 2000;
    int activationTime = -1;
    int dieTime = -1;
    int x;
    int y;
};

cell gridCell[500][500];
// vector<vector<cell>> gridCell(500, vector<cell>(500)); // 초기 그리드 크기 800 x 800선언
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m, k;

void cellConfig(cell &c, int life, int curtime, int y, int x)
{
    c.life = life;
    c.createTime = curtime;
    c.activationTime = curtime + life;
    c.dieTime = curtime + (life * 2);
    c.y = y;
    c.x = x;
}

// 활성상태 확인 함수
bool isActive(cell &curCell, int currentTime)
{
    if (curCell.activationTime <= currentTime && currentTime < curCell.dieTime)
        return true;
    return false;
}

// 세포 번식 함수
// TODO
void cellBreeding(cell &c, int curTime, vector<cell> &q)
{
    if (isActive(c, curTime))
        for (int i = 0; i < 4; i++)
        {
            int ny = c.y + dir[i][0];
            int nx = c.x + dir[i][1];

            cellConfig(gridCell[ny][nx], c.life, curTime, ny, nx);

            q.push_back(gridCell[ny][nx]);

            // if (gridCell[ny][nx].life > 0)
            // {
            //     if (gridCell[ny][nx].createTime == c.activationTime) // 현재 단계에서 생성된 것인가?
            //     {
            //         if (gridCell[ny][nx].life < newCell.life)
            //             gridCell[ny][nx] = newCell;
            //     }
            // }
            // else if (gridCell[ny][nx].life == 0)
            // {
            //     gridCell[ny][nx] = newCell;
            // }
        }
}

int solution(int curTime)
{
    int start, end;
    while (curTime <= k)
    {
        // start = 300 - curTime, end = 300 + curTime;
        for (int i = 0; i < 500; i++)
        {
            for (int j = 0; j < 500; j++)
            {
                if (gridCell[i][j].life != 0)
                    if (gridCell[i][j].activationTime == curTime)
                    {
                        vector<cell> q;
                        cellBreeding(gridCell[i][j], curTime, q);
                        sort(q.begin(), q.end(), [](cell &a, cell &b) {
                            return a.life > b.life ? true : false;
                        });

                        for (int a = 0; a < q.size(); a++)
                            if (gridCell[q[a].y][q[a].x].life == 0)
                            {
                                gridCell[q[a].y][q[a].x] = q.front();
                                q.erase(q.begin());
                            }
                    }
            }
        }
        curTime++;
    } // end of while

    int ans = 0;
    // k시간이 되면 결과 도출.
    for (int i = 0; i < 500; i++)
        for (int j = 0; j < 500; j++)
        {
            if (gridCell[i][j].createTime <= curTime && curTime < gridCell[i][j].dieTime)
                ans++;
        }
    return ans;
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    int T;
    // scanf("%d", &T);
    fs >> T;

    for (int t = 1; t <= T; t++)
    {
        int ans = 0;

        // scanf("%d %d %d", &n, &m, &k);
        fs >> n >> m >> k;
        // 초기상태 설정
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int tmp;
                // scanf("%d", &tmp);
                fs >> tmp;
                if (tmp != 0)
                    cellConfig(gridCell[200 + i][200 + j], tmp, 0, 200 + i, 200 + j);
            }

        ans = solution(1);
        printf("#%d %d\n", t, ans);
    }
    return 0;
}