#include <algorithm>
#include <iostream>

/** 종이의 개수 백준_1780 ( https://www.acmicpc.net/problem/1780 )
 *  * 9개 칸 모두 돌 수 있는 방법은?
 */

using namespace std;

int cnt[3];

bool func(int **arr, int start, int end, int dist)
{
    int tmp = arr[start][end];
    for (int i = start; i < start + dist; i++)
        for (int j = end; j < end + dist; j++)
            if (tmp != arr[i][j])
                return false;
    return true;
}

void divide(int **arr, int start, int end, int dist)
{
    if (func(arr, start, end, dist))
    {
        cnt[arr[start][end] + 1]++;
    }
    else
    {
        int nxdist = dist / 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                divide(arr, start + (nxdist * i), end + (nxdist * j), nxdist);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    divide(arr, 0, 0, n);

    printf("%d\n%d\n%d\n", cnt[0], cnt[1], cnt[2]);

    return 0;
}