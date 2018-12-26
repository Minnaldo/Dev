#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

/** Lomuto 방식 Quick Sort
 *  * 동작 방식
 *  * i가 고정상태에서 j로 배열을 돌며 피벗보다 작은 값을 찾는다
 *  * 피벗은 항상 최우측의 값, 배열의 마지막 값
 */

void quick_lomuto(int *arr, int left, int right)
{
    if (left < right)
    {
        int i = left - 1; // i : 피벗보다 작은값의 인덱스

        // 인덱스 j가 right(pivot 인덱스) 보다 작을 때까지 반복
        for (int j = 1; j < right; j++) // j : 피벗보다 큰값의 인덱스
        {
            if (arr[j] < arr[right]) // arr[right] : pivot, arr[j]의 값이 피벗보다 작을경우 arr[i+1]와 arr[j]를 스왑
            {
                swap(arr[++i], arr[j]); // i의 현재 위치는 0이기 때문에 1부터 시작하는 배열의 처음을 가리키려면 1을 증가시킨 후 연산해야 함
            }
        }

        swap(arr[++i], arr[right]); // j = right - 1 이면, pivot과 arr[i+1]을 스왑, 스왑후  i는 현재 단계의 피벗

        // 피벗을 제외한 나머지를 다시 정렬하기 위함
        quick_lomuto(arr, left, i - 1);
        quick_lomuto(arr, i + 1, right);
    }
}

/* ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ Hoare Partion ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
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