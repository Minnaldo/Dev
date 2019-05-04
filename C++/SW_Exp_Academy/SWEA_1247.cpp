#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

/**
 *  ! 시간을 줄이자, 인접행렬 -> 인접 리스트
 */

using namespace std;

int t, n, dst[10][10], ans;
vector<pair<int, int>> arr;
pair<int, int> office, home;
vector<vector<pair<int, int>>> map(10);

int min(int &a, int &b) { return a < b ? a : b; }

void init() // 각 노드에서 모든 다른 노드까지의 거리를 계산하여 인접리스트 생성
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i != j)
            {
                map[i].push_back(make_pair(abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second), j));
            }
        }
    }
}

void solution(vector<bool> visit, int curIdx, int sum, int cnt)
{
    if (cnt == n)
    {
        sum += (abs(arr[curIdx].first - home.first) + abs(arr[curIdx].second - home.second));
        ans = min(ans, sum);
    }

    int size = map[curIdx].size();

    for (int i = 0; i < size; i++)
    {
        int tmpSum = map[curIdx][i].first; // 거리 값
        int idx = map[curIdx][i].second;   // 노드 번호
        visit[idx] = true;
        solution(visit, idx, sum + tmpSum, cnt + 1);
        visit[idx] = false;
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
        {
            scanf("%d %d", &arr[i].first, &arr[i].second);
        }

        init();
        vector<bool> visit(n);
        fill_n(visit.begin(), n, false);

        for (int i = 0; i < n; i++)
        {
            int tmpSum = abs(office.first - arr[i].first) + abs(office.second - arr[i].second); // 회사에서 첫번째 집까지의 거리
            visit[i] = true;
            solution(visit, i, tmpSum, 1);
            visit[i] = false;
        }

        printf("#%d %d\n", tc, ans);

        arr.clear();

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << dst[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }

    return 0;
}