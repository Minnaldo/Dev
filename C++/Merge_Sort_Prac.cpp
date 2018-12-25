#include <iostream>

using namespace std;

int sorted[1000]; // 임시 배열

void merge(int *arr, int left, int mid, int right)
{

    int i, j, k;
    i = left;    // 앞쪽 배열의 첫 인덱스
    j = mid + 1; // 뒤쪽 배열의 첫 인덱스
    k = left;    // 임시 배열의 인덱스, merge 함수 전체에 걸쳐 k를 1씩 증가해가며 인덱스를 증가해 나가며 임시배열에 정렬된 값을 집어넣는다

    // 분할 정렬된 list 합병
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            sorted[k++] = arr[i++];
        }
        else
        {
            sorted[k++] = arr[j++];
        }
    }

    // 남아 있는 값들을 일괄 복사
    if (i > mid)
    {
        for (int l = j; l <= right; l++)
        {
            sorted[k++] = arr[l];
        }
    }
    else
    {
        for (int l = i; l <= mid; l++)
        {
            sorted[k++] = arr[l];
        }
    }

    // 임시배열을 원래 배열로 복사
    for (int l = left; l <= right; l++)
    {
        arr[l] = sorted[l];
    }
}
void merge_sort(int *arr, int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = (left + right) / 2;
        merge_sort(arr, left, mid);      // 앞쪽 부분 리스트 정렬
        merge_sort(arr, mid + 1, right); // 뒤쪽 부분 리스트 정렬
        merge(arr, left, mid, right);    // 분할된 리스트 병합
    }
}

int main(int argc, char const *argv[])
{
    int n = 10;
    int *arr = new int[n + 1];
    int size = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, 0, size);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}