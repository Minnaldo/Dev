#include <cmath>
#include <iostream>

/** 터렛 백준_1002 ( https://www.acmicpc.net/problem/1002 )
 *  두 점 사이의 거리 : sqrt( pow((x1-x2) , 2) + pow((y1-y2) , 2))
 *  * sqrt를 사용 시, int 자료형을 쓸 경우 소수점을 제대로 나타낼 수 없는 문제가 생길 수 있다.
 *  * 이를 해결하기 위해 두 원의 반지름의 차와 합을 각각 제곱하여 sqrt없이 사용할 수 있도록 한다.
 *  * 두 원이 맞닿는 점의 개수를 리턴한다.
 */

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--)
    {
        int ans = 0;
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int dst = pow((x1 - x2), 2) + pow((y1 - y2), 2); // 두 점 사이의 거리
        int rsum = pow((r1 + r2), 2);                    // 두 원의 반지름의 합
        int rminus = pow((r1 - r2), 2);                  // 반지름의 차

        if (x1 == x2 && y1 == y2 && r1 == r2)
            ans = -1;
        else if (dst == rsum || dst == rminus)
            ans = 1;
        else if (dst < rsum && dst > rminus)
            ans = 2;
        else
            ans = 0;

        cout << ans << endl;
    }

    return 0;
}