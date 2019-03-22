#include <iostream>

/** ACM 호텔 백준_10250 ( https://www.acmicpc.net/problem/10250 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int h, w, n, ans;
        scanf("%d %d %d", &h, &w, &n);

        if (n % h == 0)
        {
            ans = h * 100;
            ans += (n / h);
        }
        else
        {
            ans = (n % h) * 100;
            ans += (n / h) + 1;
        }

        printf("%d\n", ans);
    }

    return 0;
}