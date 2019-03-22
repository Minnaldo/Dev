#include <iostream>

/** 수 정렬하기 2 백준_2751 ( https://www.acmicpc.net/problem/2751 )
 *  * 여러 정렬방법 사용 가능
 */

using namespace std;

int tmparr[1000000];

void merge(int *arr, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            tmparr[k++] = arr[i++];
        else
            tmparr[k++] = arr[j++];
    }

    if (i > mid)
    {
        for (int l = j; l <= right; l++)
            tmparr[k++] = arr[l];
    }
    else
    {
        for (int l = i; l <= mid; l++)
            tmparr[k++] = arr[l];
    }

    for (int l = left; l <= right; l++)
        arr[l] = tmparr[l];
}

void devide(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        devide(arr, left, mid);
        devide(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    devide(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);

    return 0;
}