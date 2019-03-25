#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int cnt[3];

void func(int **arr, int start, int end);

void devide(int **arr, int start, int end)
{
    if (start < end)
    {
        int mid = (end - start + 1) / 3;
        func(arr, start, mid);
        func(arr, mid + 1, mid * 2);
        func(arr, (mid * 2) + 1, end);
    }
}

void func(int **arr, int start, int end)
{
    int tmp = arr[start][start];
    bool flag = false;
    // count_if(arr[start][start], arr[end][end], []() {});
    for (int i = start; i <= end; i++)
    {
        for (int j = start; j <= end; j++)
        {
            if (tmp != arr[i][j])
            {
                devide(arr, start, end);
                flag = true;
                return;
            }
        }
    }

    if (!flag)
        cnt[arr[start][start] + 1]++;
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    int n;
    // scanf("%d", n);
    fs >> n;

    int **arr = new int *[n + 1];
    for (int i = 1; i < n; i++)
    {
        arr[i] = new int[n + 1];
        for (int j = 1; j < n; j++)
        {
            // scanf("%d", &arr[i][j]);
            fs >> arr[i][j];
        }
    }

    func(arr, 1, n);

    printf("%d\n%d\n%d\n", cnt[0], cnt[1], cnt[2]);

    return 0;
}