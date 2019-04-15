#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int t, n, sy, sx, ex, ey, ans;

int solution(vector<tuple<int, int, int>> arr)
{
    int size = arr.size();
    int cnt = 0;
    for (int i = 0; i < size; i++)
    {
        int px = get<0>(arr[i]);
        int py = get<1>(arr[i]);
        int dst = get<2>(arr[i]);

        int sdst = abs(sy - py) + abs(sx - px);
        int edst = abs(ey - py) + abs(ex - px);

        if (sdst < dst)
            cnt++;
        if (edst < dst)
            cnt++;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);                          // 테스트 케이스 수
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

        ans = solution(arr);

        printf("%d\n", ans);
    }
    return 0;
}