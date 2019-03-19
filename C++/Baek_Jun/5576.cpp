#include <algorithm>
#include <iostream>

/** 콘테스트 백준_5576 ( https://www.acmicpc.net/problem/5576 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int ans = 0, tmp;
    int kscore[10], wscore[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &kscore[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &wscore[i]);
    }

    int ans1 = 0, ans2 = 0;

    for (int i = 0; i < 3; i++)
    {
        auto itr1 = max_element(kscore, kscore + 10);
        auto itr2 = max_element(wscore, wscore + 10);
        ans1 += *itr1;
        *itr1 = -1;
        ans2 += *itr2;
        *itr2 = -1;
    }

    printf("%d %d\n", ans1, ans2);
    return 0;
}