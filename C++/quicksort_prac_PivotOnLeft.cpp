#include <iostream>

using namespace std;

/**
 *  pivot값이 좌측에 있을 경우
 */

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int quick(int arr[], int start, int end)
{
    int pivot = start;
    int l = start + 1, r = end;

    while (l < r)
    {
        while (arr[pivot] < arr[l])
        {
            l++;
        }
        while (arr[pivot] > arr[r])
        {
            r--;
        }

        if (l < r)
        {
            swap(arr[l], arr[r]);
        }
    }

    swap(arr[pivot], arr[r]);

    return pivot;
}

void partition(int arr[], int start, int end)
{
    if (start < end)
    {
        int q = quick(arr, start, end);

        partition(arr, start, q - 1);
        partition(arr, q + 1, end);
    }
}

int main(int argc, char const *argv[])
{
    int arr[10] = {3, 2, 4, 1, 5, 9, 6, 10, 8, 7};
    partition(arr, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}