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
            M -= 45;
        }
        else
        {
            H -= 1;
            M = 60 - (45 - M);
        }
    }
    else
    {
        H = 23;
        M = 60 - (45 - M);
    }

    cout << H << " " << M << endl;
    return 0;
}