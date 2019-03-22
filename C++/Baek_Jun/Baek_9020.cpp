#include <cmath>
#include <iostream>

/** 골드바흐의 추측 백준_9020 ( https://www.acmicpc.net/problem/9020 )
 *
 */

using namespace std;

bool arr[10001];

int main(int argc, char const *argv[])
{
    arr[1] = true;
    for (int i = 2; i <= 10000; i++)
    {
        if (!arr[i])
            for (int j = i * 2; j <= 10000; j += i)
                arr[j] = true;
    }

    int T, n;
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &n);
        int tmp = 100000, ans1, ans2;
        for (int i = 2; i <= (n - 2); i++)
        {
            if (!arr[i] && !arr[n - i] && (i + (n - i)) == n)
            {
                int aa = abs(i - (n - i));
                if (tmp > aa)
                {
                    tmp = aa;
                    ans1 = i;
                    ans2 = n - i;
                }
            }
        }

        if (ans1 <= ans2)
            printf("%d %d\n", ans1, ans2);
        else
            printf("%d %d\n", ans2, ans1);
    }
    return 0;
}