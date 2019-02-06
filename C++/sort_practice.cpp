#include <iostream>

using namespace std;

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// arr[l] 은 arr[pivot] 보다 큰 값, arr[r]은 arr[pivot]보다 작은 값 탐색 후 이 둘 스왑
void quick(int *arr, int start, int end)
{
    // pivot 인덱스를 가장 처음 원소로 설정
    int pivot_idx = start;
    int l = start + 1, r = end;
    while (l < r)
    {
        while (arr[l] < arr[pivot_idx])
        {
            l++;
        }
        while (arr[r] > arr[pivot_idx])
        {
            r--;
        }

        if (l < r)
        {
            swap(arr[l], arr[r]);
        }
        else
        {
            swap(arr[l], arr[pivot_idx]);
        }
        quick(arr, start, l);
        quick(arr, l + 1, end);
    }
}

int main(int argc, char const *argv[])
{
    int arr[11] = {2, 5, 1, 7, 9, 10, 6, 7, 3, 8, 4};

    quick(arr, 0, 10);

    for (int i = 0; i <= 10; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}