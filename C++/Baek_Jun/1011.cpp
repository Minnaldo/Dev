#include <iostream>

using namespace std;

/** Fly me to the Alpha Centauri 백준_1011 ( https://www.acmicpc.net/problem/1011 )
 *  NOTE  자료형으로 인해 시간초과가 발생할 수 있다.
 */

int main(int argc, char const *argv[])
{
    int T, ans;
    scanf("%d", &T);

    for (int a = 0; a < T; a++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        long long dis = y - x, po, idx = 1;
        do
        {
            po = idx * idx;
            if ((po - idx) < dis && dis <= po + idx)
            {
                if (dis <= po)
                    ans = (idx << 1) - 1;
                else
                    ans = (idx << 1);
                break;
            }
            idx++;
        } while (dis >= po);

        printf("%d\n", ans);
    }

    return 0;
}