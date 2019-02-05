#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int arr[], int start, int end)
{
    int pivot = end;
    int idx1 = start, idx2 = start + 1;

    if (start < end)
    {
        while (arr[pivot] > arr[idx2])
        {
            idx2++;
        }
        while (arr[pivot] < arr[idx1])
        {
            idx1++;
        }

        if (idx2 < end)
        {
            swap(arr[idx1], arr[idx2]);
        }
    }

    swap(arr[idx1 + 1], arr[pivot]);
    partition(arr, start, idx1);
    partition(arr, idx1 + 2, end);
}

int main(int argc, char const *argv[])
{
    int arr[10] = {3, 2, 4, 1, 5, 9, 6, 10, 8, 7};

    partition(arr, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}