#include <cmath>
#include <iostream>

/** 앵그리 창영 백준_3034 ( https://www.acmicpc.net/problem/3034 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int n, w, h;
    scanf("%d %d %d", &n, &w, &h);

    int dia = sqrt((w * w) + (h * h));
    int tmp;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if (tmp <= dia)
        {
            printf("DA\n");
        }
        else
        {
            printf("NE\n");
        }
    }
    return 0;
}