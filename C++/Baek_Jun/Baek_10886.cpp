#include <algorithm>
#include <iostream>

/** 0 = not cute / 1 = cute 백준_10886 ( https://www.acmicpc.net/problem/10886 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N, ans = 0, tmp;
    fs >> N;

    for (int i = 0; i < N; i++)
    {
        fs >> tmp;
        ans += tmp;
    }

    if (ans > (N - ans))
    {
        cout << "Junhee is cute!" << endl;
    }
    else
    {
        cout << "Junhee is not cute!" << endl;
    }

    return 0;
}