#include <algorithm>
#include <iostream>
#include <vector>

/** 보물왕 태혁 7829
 *
 */

using namespace std;

int t, n;

int solution(vector<int> &aa)
{
    sort(aa.begin(), aa.end());

    if (n > 2)
    {
        return aa.front() * aa.back();
    }
    else if (n == 2)
    {
        return aa.front() * aa.back();
    }
    else
    {
        return aa.front() * aa.front();
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d", &n);
        vector<int> arr(n, 0);

        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        printf("#%d %d\n", tc, solution(arr));
    }
    return 0;
}