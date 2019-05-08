#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 *  ! 조금 더 빠르게 가능 할 듯
 */

int t, n, ans;
vector<pair<int, int>> arr;
pair<int, int> office, home;
vector<vector<pair<int, int>>> adj_list;

int min(int &a, int &b) { return a < b ? a : b; }

void init() // 각 노드에서 모든 다른 노드까지의 거리를 계산하여 인접리스트 생성
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                adj_list[i].push_back(make_pair(j, abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second)));
            }
        }
    }

    // 거리 순으로 정렬
    for (int i = 0; i < n; i++)
    {
        sort(adj_list[i].begin(), adj_list[i].end(), [](pair<int, int> f, pair<int, int> s) {
            return f.second < s.second ? true : false;
        });
    }
}

void solution(vector<bool> visit, int curIdx, int sum, int cnt)
{
    if (sum > ans)
        return;

    if (cnt == n)
    {
        sum += (abs(arr[curIdx].first - home.first) + abs(arr[curIdx].second - home.second));
        ans = min(ans, sum);
        return;
    }

    for (int i = 0; i < adj_list[curIdx].size(); i++)
    {
        int tmpSum = adj_list[curIdx][i].second;
        int idx = adj_list[curIdx][i].first;

        if (!visit[idx] && idx != curIdx)
        {
            visit[idx] = true;
            solution(visit, idx, sum + tmpSum, cnt + 1);
            visit[idx] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);

    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d", &n);
        ans = 987654321;
        scanf("%d %d", &office.first, &office.second);
        scanf("%d %d", &home.first, &home.second);

        arr.assign(n, pair<int, int>());

        for (int i = 0; i < n; i++)
            scanf("%d %d", &arr[i].first, &arr[i].second);

        adj_list.assign(n, vector<pair<int, int>>());
        init();
        vector<bool> visit;
        visit.assign(n, false);

        for (int i = 0; i < n; i++)
        {
            int tmpSum = abs(office.first - arr[i].first) + abs(office.second - arr[i].second); // 회사에서 첫번째 집까지의 거리
            visit[i] = true;
            solution(visit, i, tmpSum, 1);
            visit[i] = false;
        }

        printf("#%d %d\n", tc, ans);
        arr.clear();
    }

    return 0;
}