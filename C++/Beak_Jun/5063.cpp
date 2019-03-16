#include <iostream>

/** TGN 백준_5063 ( https://www.acmicpc.net/problem/5063 )
 *  NOTE  point) printf와 scanf를 써야 빠르다
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N;
    scanf("%d", &N);

    for (int a = 0; a < N; a++)
    {
        int r, e, c;
        scanf("%d %d %d", &r, &e, &c);

        if (r == (e - c))
            printf("does not matter\n");
        else if (r > (e - c))
            printf("do not advertise\n");
        else
            printf("advertise\n");
    }

    return 0;
}