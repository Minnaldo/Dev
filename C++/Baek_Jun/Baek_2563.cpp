#include <iostream>

/** 색종이 백준_2563 ( https://www.acmicpc.net/problem/2563 )
 *
 */

using namespace std;

bool arr[101][101];

int main(int argc, char const *argv[])
{
    int n, cnt = 0;
    scanf("%d", &n);

    for (int a = 0; a < n; a++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        int xend = x + 10, yend = y + 10;

        for (int i = y; i < yend; i++)
            for (int j = x; j < xend; j++)
                arr[i][j] = true;
    }

    for (int i = 1; i <= 100; i++)
        {
            for (int j = 1; j <= 100; j++)
            {
                if (arr[i][j])
                    cnt++;
            }
        }

    printf("%d\n", cnt);
    return 0;
}