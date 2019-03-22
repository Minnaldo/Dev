#include <iostream>

/** 부녀회장이 될테야 백준_2775 ( https://www.acmicpc.net/problem/2775 )
 *
 */

using namespace std;

int arr[15][15];

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= 14; i++)
        arr[0][i] = i;

    for (int i = 1; i < 15; i++)
        for (int j = 1; j < 15; j++)
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];

    while (N--)
    {
        int k, n;
        scanf("%d %d", &k, &n);

        printf("%d\n", arr[k][n]);
    }

    return 0;
}