#include <iostream>
#include <vector>

using namespace std;

int t, ans, n, w;
vector<vector<int>> section;
vector<bool> visit;

int min(int &a, int &b) { return a < b ? a : b; }

// 최대한 많은 소대가 2개 구역을 맡아야 최소값이 나온다
int solution()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
    }

    return cnt;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);

    while (t--)
    {
        ans = 0;
        scanf("%d %d", &n, &w);

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                section[i].push_back(tmp);
            }
        }

        ans = n * 2; // 이론상 최댓값

        ans = min(ans, solution());
        printf("%d\n", ans);
        section.clear();
    }

    return 0;
}