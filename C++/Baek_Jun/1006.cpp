#include <cstring>
#include <deque>
#include <iostream>

// 인접 영역 커버 가능? ==> 가장 많은 적을 처리할 수 있는 영역 선택
// 인접 영역 커버 불가? ==> 해당 구역인덱스와 같은 visit배열 인덱스를 true로 체크 후 넘어감

using namespace std;

int t, ans, n, w;
bool visit[2][10000];

int solution(deque<deque<int>> dq)
{
    auto itr1 = dq[0].begin();
    auto itr2 = dq[1].begin();

    for (int i = 0; i < n; i++)
    {

        if (i == 0)
        {
        }
        else if (i == n - 1)
        {
        }
        else
        {
        }
    }
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);

    while (t--)
    {
        ans = 0;
        memset(visit, false, sizeof(visit));
        scanf("%d %d", &n, &w);

        deque<deque<int>> dq(2, deque<int>(n));

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &dq[i][j]);
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}