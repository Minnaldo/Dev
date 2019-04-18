#include <cmath>
#include <iostream>

/** 어린왕자 백준_1004 ( https://www.acmicpc.net/problem/1004 )
 *  ? 두 점 사이의 거리가 아닌, 원의 넓이에 포함을 해야하는가??
 *  Ponit) 출발점과 끝점이, 궤도 내부에 포함하는지를 확인한다 ( 궤도 좌표를 기준으로 한 원의 넓이 내에 들어가는지 확인 한다 )
 *  ==> 원의 넓이 공식 : x^2 + y^2 = r^2
 *  Point 2) 출발점과 끝점이 하나의 궤도에 들어가 있는경우도 존재할 수 있으므로, 이 경우는 카운팅 하지 않는다.
 */

using namespace std;

int t, n, sy, sx, ex, ey, ans;

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);

    scanf("%d", &t); // 테스트 케이스 수
    for (int tc = 1; tc <= t; tc++)
    {
        ans = 0;
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey); // 출발점, 도착좀
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            int px, py, r;
            scanf("%d %d %d", &px, &py, &r);

            int start = abs(px - sx) + abs(py - sy);
            int end = abs(px - ex) + abs(py - ey);

            if ((px - sx) * (px - sx) + (py - sy) * (py - sy) <= r * r || (px - ex) * (px - ex) + (py - ey) * (py - ey) <= r * r)
                ans++;
            if ((px - sx) * (px - sx) + (py - sy) * (py - sy) <= r * r && (px - ex) * (px - ex) + (py - ey) * (py - ey) <= r * r)
                ans--;
        }

        printf("%d\n", ans);
    }
    return 0;
}