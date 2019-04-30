#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

/**
 *
 */

using namespace std;

int t, n, curMin, dst[10][10];
bool visit[10];
vector<pair<int, int>> arr;
pair<int, int> office, home;

void init()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                dst[i][j] = 0;
            }
            else
            {
                dst[i][j] = abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second);
            }
        }
    }
}

int solution(int curIdx, int sum)
{
    int nxtIdx = -1;
    int tmpdst = 9999;
    for (int i = 0; i < n; i++)
    {
        if (i != curIdx && !visit[i])
        {
            if (tmpdst > dst[curIdx][i])
            {
                nxtIdx = i;
                tmpdst = dst[curIdx][i];
            }
        }
    }

    if (nxtIdx != -1)
    {
        visit[nxtIdx] = true;
        solution(nxtIdx, sum + dst[curIdx][nxtIdx]);
    }
    else
    {
        return sum += (abs(arr[curIdx].first - home.first) + abs(arr[curIdx].second - home.second));
    }
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);

    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d", &n);

        scanf("%d %d", &office.first, &office.second);
        scanf("%d %d", &home.first, &home.second);

        arr.assign(n, pair<int, int>());
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &arr[i].first, &arr[i].second);
        }

        init();
        int idx = 0;
        int tmpdst = abs(office.first - arr[0].first) + abs(office.second - arr[0].second);
        for (int i = 1; i < n; i++)
        {
            if (abs(office.first - arr[i].first) + abs(office.second - arr[i].second) < tmpdst)
            {
                idx = i;
                tmpdst = abs(office.first - arr[i].first) + abs(office.second - arr[i].second);
            }
        }

        visit[idx] = true;
        int ans = solution(idx, tmpdst);

        printf("#%d %d\n", tc, ans);

        memset(visit, false, sizeof(visit));
        arr.clear();
    }

    return 0;
}