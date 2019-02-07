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

// 배열의 원소가 여러개가 될 수 있음 ==> 각각 하나씩 전부 비교해서 정렬을 해줘야함
// 그러므로, 임시배열의 존재가 필요
// conquer part
void conquer(int *arr, int start, int mid, int end)
{
    int i = start, j = mid + 1;
    int tmpStart = start; // 임시 배열의 시작 인덱스

    // 들어온 두개의 배열중 하나의 배열의 마지막 인덱스에 도달하기 전까지 정렬
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temparr[tmpStart++] = arr[i++];
        }
        else
        {
            temparr[tmpStart++] = arr[j++];
        }
    }

    if (i > mid) // i <= mid : my code
    {
        while (j <= end)
        {
            temparr[tmpStart++] = arr[j++];
        }
    }
    else
    {
        while (i <= mid)
        {
            temparr[tmpStart++] = arr[i++];
        }
    }

    // 임시 배열에서 원래 배열로 복사
    for (int i = start; i <= end; i++)
    {
        arr[i] = temparr[i];
    }
} // end of conquer function

// divide part
void devide(int *arr, int start, int end)
{
    // 배열이 두개 이상일 때만 배열을 나눠서 다음 작업을 진행해야 하므로
    // 첫 인덱스가 끝 인덱스보다 작을때만 실행하도록 한다
    if (start < end)
    {
        int mid = (end + start) / 2;
        devide(arr, start, mid);
        devide(arr, mid + 1, end);
        conquer(arr, start, mid, end);
    }

} // end of devide function

int main(int argc, char const *argv[])
{
    int arr[MAX] = {3, 2, 4, 1, 5, 9, 6, 10, 8, 7};

    int arrSize = sizeof(arr) / sizeof(arr[0]);
    cout << "ArrSize : " << arrSize << endl;
    devide(arr, 0, MAX - 1);

    for (int i = 0; i < MAX; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}