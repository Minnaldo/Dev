#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/** 옥희의 OK! 부동산 SWEA_7812 ( https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWslJ57qFS0DFASy&categoryId=AWslJ57qFS0DFASy&categoryType=CODE )
 *  * 이어지는 구간의 합이 M인 경우의 수를 반환하라
 */

using namespace std;

int t, n, m;
vector<int> arr(10000, 0);

int solution()
{
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int tmp = arr[i];
        if (tmp == m)
        {
            ans++;
            continue;
        }
        else if (tmp < m)
        {
            for (int j = i + 1; j < n; j++)
            {
                tmp += arr[j];
                if (tmp > m)
                    break;

                if (tmp == m)
                    ans++;
            }
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        printf("#%d %d\n", tc, solution());
        fill_n(arr.begin(), n, 0);
    }
    return 0;
}