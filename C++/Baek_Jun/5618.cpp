#include <algorithm>
#include <iostream>

/** 공약수 백준_5618 ( https://www.acmicpc.net/problem/5618 )
 *  * 현재 구현된것은 완전탐색 방법 ==> 시간을 줄이는 방법이 분명 있을 것이다.
 *  TODO
 */

using namespace std;

bool dp[100000001];

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min = *min_element(arr, arr + n);

    for (int i = 1; i <= min; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if ((arr[j] % i) == 0)
                cnt++;
        }

        if (cnt == n)
            printf("%d\n", i);
    }

    return 0;
}