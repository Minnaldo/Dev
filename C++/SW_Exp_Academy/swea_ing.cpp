#include <iostream>

using namespace std;

int s, e, m;

int solution()
{
    int cnt = 1;
    int ss = 1, ee = 1, mm = 1;

    while (true)
    {
        if (ss > 365)
            ss = 1;
        else
            ss++;
        if (ee > 24)
            ee = 1;
        else
            ee++;
        if (mm > 29)
            mm = 1;
        else
            mm++;

        cnt++;
        if (ss == s && mm == m && ee == e)
            return cnt;
    }
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    int tc;
    scanf("%d", &tc);

    for (int t = 1; t <= tc; t++)
    {
        int ans = 0;

        scanf("%d %d %d", &s, &e, &m);

        ans = solution();

        printf("#%d %d\n", t, ans);
    }
    return 0;
}