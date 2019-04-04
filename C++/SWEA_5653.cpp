#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct cell
{
    int life = 0;
    int createTime = 1001;
    int activationTime;
    int dieTime;
    int x;
    int y;
    bool flag = false;
};

vector<vector<cell>> gridCell(650, vector<cell>(650)); // 초기 그리드 크기 800 x 800선언
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m, k;

cell cellConfig(int life, int curtime, int y, int x)
{
    cell c;
    c.life = life;
    c.createTime = curtime;
    c.activationTime = curtime + life;
    c.dieTime = curtime + (life * 2);
    c.y = y;
    c.x = x;
    c.flag = true; // true =  세포 존재, false = 세포 없음

    return c;
}

// 활성상태 확인 함수
bool isActive(int currentTime, cell &curCell)
{
    if (curCell.activationTime <= currentTime && curCell.dieTime > currentTime)
        return true;
    return false;
}

// 세포 번식 함수
// TODO
void cellBreeding(cell &c, int curTime)
{
    if (isActive(curTime, c))
        for (int i = 0; i < 4; i++)
        {
            int ny = c.y + dir[i][0];
            int nx = c.x + dir[i][1];

            cell newCell = cellConfig(c.life, curTime, ny, nx);

            if (gridCell[ny][nx].flag)
            {
                if (gridCell[ny][nx].createTime == curTime) // 동시 여부 판단
                    if (gridCell[ny][nx].life < newCell.life)
                        gridCell[ny][nx] = newCell;
            }
            else
                gridCell[ny][nx] = newCell;
        }
}

int solution(int curTime)
{
    int start, end;
    while (curTime <= k)
    {
        start = 300 - curTime, end = 300 + curTime;
        for (int i = start; i < end + n; i++)
        {
            for (int j = start; j < end + m; j++)
            {
                if (gridCell[i][j].activationTime + 1 == curTime)
                {
                    cellBreeding(gridCell[i][j], curTime);
                }
            }
        }
        curTime++;
    } // end of while

    int ans = 0;
    // k시간이 되면 번식을 끝낸다.
    for (int i = start; i < end + n; i++)
        for (int j = start; j < end + m; j++)
        {
            if (gridCell[i][j].createTime <= k && k < gridCell[i][j].dieTime)
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
                {
                    cell c = cellConfig(tmp, 0, 300 + i, 300 + j);
                    gridCell[300 + i][300 + j] = c;
                }
            }

        ans = solution(1);
        printf("#%d %d\n", t, ans);
    }
    return 0;
}