#include <iostream>

/**
 *  * 정렬되지 않은 정수형 자료의 집합에서 k번째로 큰 값(작은 값), 또는 중간값을 찾는 문제
 *  * 분할 알고리즘을 통해 O(N)시간에 찾을 수 있음
 *  REVIEW
 */

using namespace std;

int swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int quick_select(int *arr, int k, int left, int right)
{
    int i, j;

    // arr[left] : pivot
    do
    {
        i = left, j = right;

        while (i < j) // 배열의 개수가 2개 이상일 때
        {
            // pivot(arr[left]) 값보다 큰 값의 인덱스를 i값을 증가시켜가며 찾는다
            while (i <= right && arr[i] <= arr[left])
                i++;
            // pivot(arr[left]) 값보다 작은 값의 인덱스를 j값을 감소시켜가며 찾는다
            while (arr[j] > arr[left])
                j--;

            // 이전에 찾은 인덱스의 값들을 스왑
            if (i < j)
                swap(arr[i], arr[j]);
        }
        // 현 단계에서의 pivot값을 기준으로 정렬이 끝났으므로 pivot값과 arr[j]를 스왑
        // arr[i]가 아닌 arr[j]인 이유 : i는 pivot 보다 큰값의 인덱스 j는 pivot보다 작은 값의 인덱스인데
        // pivot의 위치가 배열의 가장 처음이므로 pivot보다 작은 값과 swap을 해야함, 그러므로 arr[left](pivot)과 arr[j](pivot보다작은값)을 swap
        swap(arr[left], arr[j]);

        if (j < k)
            left = j + 1;
        else
            right = j - 1;
    } while (j != k);

    return arr[j];
}

int main(int argc, char const *argv[])
{
    return 0;
}