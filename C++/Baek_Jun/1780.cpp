#include <algorithm>
#include <fstream>
#include <iostream>

/**
 *  TOOD need to more think
 */

using namespace std;

int cnt[3];

void func(int **arr, int start, int end);

void devide(int **arr, int start, int end)
{
    if (start <= end)
    {
        // 파티션이 잘못되었는데
        int dist = (end - start + 1) / 3;
        func(arr, start, start + dist - 1);
        func(arr, start + dist, start + dist + dist - 1);
        func(arr, start + dist + dist, end);
    }
}

void func(int **arr, int start, int end)
{
    int dist = (end - start + 1) / 3;
    if (dist > 1)
    {
        int tmp = arr[start][start];
        for (int i = start; i <= end; i++)
        {
            for (int j = start; j <= end; j++)
            {
                if (tmp != arr[i][j])
                {
                    devide(arr, start, end);
                    return;
                }
            }
        }

        cnt[tmp + 1]++;
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            for (int j = start; j <= end; j++)
            {
                cnt[arr[i][j] + 1]++;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    int n;
    // scanf("%d", n);
    fs >> n;

    int **arr = new int *[n + 1];
    for (int i = 1; i <= n; i++)
    {
        arr[i] = new int[n + 1];
        for (int j = 1; j <= n; j++)
        {
            // scanf("%d", &arr[i][j]);
            fs >> arr[i][j];
        }
    }

    func(arr, 1, n);

    printf("%d\n%d\n%d\n", cnt[0], cnt[1], cnt[2]);

    return 0;
}