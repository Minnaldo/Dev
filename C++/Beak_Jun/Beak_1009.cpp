#include <iostream>
#include <math.h>

/** 분산처리 백준_1009 ( https://www.acmicpc.net/problem/1009 )
 *  NOTE  b승을 구하는 것의 속도를 줄이는 방법은 없을까??
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int a, b;
        cin >> a >> b;

        long long tmp = 1;

        for (int j = 0; j < b; j++)
        {
            tmp = (tmp * a) % 10;
        }

        if (tmp == 0)   // ! key point
            cout << 10 << endl;
        else
            cout << tmp << endl;
    }
    return 0;
}