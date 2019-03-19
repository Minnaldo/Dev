#include <iostream>

/** 거스름돈 백준_5585 ( https://www.acmicpc.net/problem/5585 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    int tmp = 1000 - N;
    int coin = 500, ans = 0;

    for (int i = 6; i > 0; i--)
    {
        if (i % 2 == 0)
        {
            ans += tmp / coin;
            tmp %= coin;
            coin /= 5;
        }
        else
        {
            ans += tmp / coin;
            tmp %= coin;
            coin /= 2;
        }
    }

    cout << ans << endl;

    return 0;
}