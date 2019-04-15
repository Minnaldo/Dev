#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int t, n, sy, sx, ex, ey, ans;

int solution()
{
}

int main(int argc, char const *argv[])
{
    scanf("%d", t);
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey); // 출발점, 도착좀
    for (int tc = 1; tc <= t; tc++)
    {
        ans = 0;
        scanf("%d", &n);
        int tmp1, tmp2, tmp3;
        vector<tuple<int, int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
            arr.push_back(make_tuple(tmp1, tmp2, tmp3));
        }

        ans = solution();

        printf("%d\n", ans);
    }
    return 0;
}