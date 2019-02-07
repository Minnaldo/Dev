#include <iostream>

using namespace std;

#define MAX 10

int temparr[MAX];

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void merge(int arr[], int start, int end)
{
    int mid = (end + start) / 2;

    if (mid > 0)
    {
        merge(arr, start, mid);
        merge(arr, mid + 1, end);
    }
    array_merge(arr, start, end);
} // end of merge function

// 배열의 원소가 여러개가 될 수 있음 ==> 각각 하나씩 전부 비교해서 정렬을 해줘야함
// 그러므로, 임시배열의 존재가 필요
// end - start = size of arr
void array_merge(int arr[], int start, int end)
{

} // end of array_merge function

int main(int argc, char const *argv[])
{
    int arr[MAX] = {3, 2, 4, 1, 5, 9, 6, 10, 8, 7};

    merge(arr, 0, MAX);

    for (int i = 0; i < MAX; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}