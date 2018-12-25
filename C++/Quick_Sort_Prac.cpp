#include <iostream>

using namespace std;

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// 피벗의 위치를 반환한다
int partition(int *arr, int left, int right)
{
    int low = left;
    int high = right + 1;
    int pivot = arr[left];

    do
    {
        do
        {
            low++; // low는 left+1에서 시작
            // arr[low]가 피벗 인덱스의 값보다 크거나 right보다 클 때까지 low + 1
        } while (low <= right && arr[low] < pivot);

        do
        {
            high--;
            // arr[high]가 피벗 인덱스의 값보다 작거나 left보다 작을때까지 high - 1
        } while (high >= left && arr[high] > pivot);

        // low와 high가 교차하지 않았는데, arr[low] > arr[high]이면 스왑
        if (low < high)
        {
            swap(arr[low], arr[high]);
        }

    // low 가 high보다 커지면 루프 종료
    } while (low < high);

    // arr[left]와 arr[high]를 교환
    swap(arr[left], arr[high]);

    return high; // 피벗 인덱스 반환
}

void quick_sort(int *arr, int left, int right)
{
    // 정렬할 범위가 2개 이상의 데이터이면 (배열의 크기가 2 이상이면)
    if (left < right)
    {
        // 피벗을 기준으로 리스트를 비균등 분할
        // 피벗 기준 앞의 값들은 피벗보다 작고, 뒤쪽 값들은 피벗보다 크다
        int q = partition(arr, left, right); // q : 피벗의 위치
    }

    // 피벗을 제외한 2개의 부분 리슽를 대상으로 순환 호출
    quick_sort(arr, left, q - 1);  // 앞쪽 부분 리스트 정렬
    quick_sort(arr, q + 1, right); // 뒤쪽 부분 리스트 정렬
}

int main(int argc, char const *argv[])
{
    int n; //배열 사이즈
    int *arr = new int[n + 1];

    quick_sort(arr, 0, n - 1);

    // 정렬 결과 출력
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}