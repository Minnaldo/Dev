#include <cmath>
#include <iostream>

using namespace std;

int map[20000][20000];
int T, x1, y1, r1, x2, y2, r2, ans;

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);

    scanf("%d", &T);

    while (T--)
    {
        int cnt = 0;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int startX1 = x1 - r1;
        int startY1 = y1 - r1;
        int startX2 = x2 - r2;
        int startY2 = y2 - r2;

        for (int i = startY1; i < startY1 + r1; i++)
        {
            for (int j = startX1; j < startX1 + r1; j++)
            {
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}