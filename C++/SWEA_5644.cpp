#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct bCharger
{
    int x, y;
    int size;
    int power;
};

bool charge1[8], charge2[8];
int people[2][102];
int dir[5][2] = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<bCharger> bcharger(9);

int findMax(int a)
{
    int ans = 0;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            int tmp = 0;
            if (i == j)
            {
                if (charge1[i] || charge2[j])
                    tmp = bcharger[i].power;
            }
            else
            {
                if (charge1[i])
                    tmp += bcharger[i].power;
                if (charge2[j])
                    tmp += bcharger[j].power;
            }
            ans = ans > tmp ? ans : tmp;
        }
    }
    return ans;
}

int solution(int m, int a)
{
    int nx1 = 1, ny1 = 1, nx2 = 10, ny2 = 10, ans = 0;

    int idx = 0;
    while (idx <= m)
    {
        int direction1 = people[0][idx];
        int direction2 = people[1][idx];
        nx1 += dir[direction1][1];
        ny1 += dir[direction1][0];
        nx2 += dir[direction2][1];
        ny2 += dir[direction2][0];
        // BC의 충전범위 판정
        for (int i = 0; i < a; i++)
        {
            if (abs(nx1 - bcharger[i].x) + abs(ny1 - bcharger[i].y) <= bcharger[i].size)
                charge1[i] = true;
            if (abs(nx2 - bcharger[i].x) + abs(ny2 - bcharger[i].y) <= bcharger[i].size)
                charge2[i] = true;
        }

        ans += findMax(a);

        for (int i = 0; i < a; i++)
            charge1[i] = charge2[i] = false;

        idx++;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++)
    {
        int ans = 0;
        int M, A;
        scanf("%d %d", &M,&A);

        // 이동 시간당 방향 입력
        for (int j = 0; j < 2; j++)
            for (int i = 1; i <= M; i++)
                scanf("%d", &people[j][i]);

        for (int i = 0; i < A; i++)
        {
            // BC의 정보를 받는다
            //scanf("%d %d %d %d", bcharger[i].x, bcharger[i].y, bcharger[i].size, bcharger[i].power);
            cin>>bcharger[i].x>> bcharger[i].y>> bcharger[i].size>> bcharger[i].power;  //??
        }

        ans = solution(M, A);

        printf("#%d %d\n", t, ans);
        bcharger.clear();
    }
    return 0;
}