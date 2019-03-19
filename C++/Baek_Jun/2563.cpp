#include <iostream>

/** 알람 시계 백준_2884 ( https://www.acmicpc.net/problem/2884 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int H, M;
    cin >> H >> M;

    if (H != 0)
    {
        if (M > 45)
        {
            cout << H << " " << M - 45 << endl;
        }
        else
        {
            cout << H - 1 << " " << 60 - (45 - M) << endl;
        }
    }
    else
    {
        if (M <= 45)
            cout << 23 << " " << 60 - (45 - M) << endl;
    }

    return 0;
}