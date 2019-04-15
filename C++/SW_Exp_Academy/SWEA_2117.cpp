#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int map[21][21];
vector<pair<int, int>> house(400); // 집 좌표 저장
int t, n, m, ans, houseSize, profit;

// y, x 좌표에서 서비스 가능한 집의 수
int houseCount(int k, int y, int x)
{
    int houseCnt = 0;
    for (int i = 0; i < houseSize; i++)
    {
        if (k > abs(y - house[i].first) + abs(x - house[i].second))
            houseCnt++;
    }

    if (houseCnt < ans)
        return 0;

    return houseCnt;
}

// 보안회사가 손해보지 않는 선에서 서비스 제공 최대 집 출력
int main(int argc, char const *argv[])
{
    // scanf("%d", &t);
    fstream fs("input.txt");
    fs >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        ans = 1, profit = 0, houseSize = 0;
        int houseidx = 0;
        // scanf("%d %d", &n, &m);
        fs >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // scanf("%d", &map[i][j]);
                fs >> map[i][j];
                if (map[i][j] == 1)
                {
                    house[houseidx] = make_pair(i, j);
                    houseSize++;
                    houseidx++;
                }
            }
        }

        int kend = n * n;
        for (int k = 2; k <= kend; k++)
        {
            int cost = (k * k) + ((k - 1) * (k - 1));

            // 예상 수익보다 비용이 커지면 종료 ==> 예상 수익 = 총 집의 수 * 집당 비용(m)
            if (cost > houseSize * m)
                break;

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    int ret = houseCount(k, i, j);
                    if (ret != 0 && ret > ans)
                    {
                        if ((ret * m) - cost >= 0)
                        {
                            ans = ans > ret ? ans : ret;
                        }
                    }
                }
            }
        }

        printf("#%d %d\n", tc, ans);
    }
    return 0;
}