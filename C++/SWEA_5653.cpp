#include <fstream>
#include <iostream>
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

vector<vector<cell>> gridCell(650, vector<cell>(650)); // 초기 그리드 크기 800 x 800선언
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
    if (curCell.activationTime <= currentTime && curCell.dieTime > currentTime)
        return true;
    return false;
}

// 세포 번식 함수
// TODO
void cellBreeding(cell &c, int curTime)
{
    for (int i = 0; i < 4; i++)
    {
        // 현재 세포에서 번식할 때 생기는 세포의 좌표
        int ny = c.y + dir[i][0];
        int nx = c.x + dir[i][1];
        cell newCell;
        cellConfig(newCell, c.life, curTime, ny, nx);

        // 번식할때의 조건을 명확하게 세워야 한다.
    }
}

int solution(int curTime)
{
    int start, end;
    while (curTime <= k)
    {
        // start = 300 - curTime, end = 300 + curTime;
        for (int i = 0; i < 650; i++)
        {
            for (int j = 0; j < 650; j++)
            {
                if (gridCell[i][j].life != 0 && gridCell[i][j].activationTime == curTime - 1)
                    cellBreeding(gridCell[i][j], curTime);
            }
        }
        curTime++;
    } // end of while

    int ans = 0;
    // k시간이 되면 결과 도출.
    for (int i = 0; i < 650; i++)
        for (int j = 0; j < 650; j++)
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
                {
                    cell c;
                    cellConfig(c, tmp, 0, 300 + i, 300 + j);
                    gridCell[300 + i][300 + j] = c;
                }
            }

        ans = solution(1);
        printf("#%d %d\n", t, ans);
    }
    return 0;
}