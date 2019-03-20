#include <iostream>

/** 수들의 합 백준_1789 ( https://www.acmicpc.net/problem/1789 )
 *  TODO
 */

using namespace std;

int main(int argc, char const *argv[])
{
    long long S, n = 0, idx = 0, ans = 0;

    cin >> S;

    while (true)
    {
        if (n > S)
            break;
        n += (++idx);
        ans++;
    }

    cout << ans - 1 << endl;

    return 0;
}