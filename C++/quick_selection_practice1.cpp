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

int quick_select(int *arr, int k, int start, int end)
{
    int left = start, right = end;

    // arr[start] : pivot
    do
    {
        while (left < right) // 배열의 개수가 2개 이상일 때
        {
            // pivot(arr[start]) 값보다 큰 값의 인덱스를 left값을 증가시켜가며 찾는다
            while (left <= end && arr[left] <= arr[start])
                left++;
            // pivot(arr[start]) 값보다 작은 값의 인덱스를 right값을 감소시켜가며 찾는다
            while (arr[right] > arr[start])
                right--;

            // 이전에 찾은 인덱스의 값들을 스왑
            if (left < right)
                swap(arr[left], arr[right]);
        }
        // 현 단계에서의 pivot값을 기준으로 정렬이 끝났으므로 pivot값과 arr[right]를 스왑
        // arr[left]가 아닌 arr[right]인 이유 : left는 pivot 보다 큰값의 인덱스 right는 pivot보다 작은 값의 인덱스인데
        // pivot의 위치가 배열의 가장 처음이므로 pivot보다 작은 값과 swap을 해야함, 그러므로 arr[start](pivot)과 arr[right](pivot보다작은값)을 swap
        swap(arr[start], arr[right]);

        // 재귀함수를 쓰지 않고 반복문을 통해 로직 구성
        // 마지막에 right와 pivot을 스왑 하였으므로, 밑으로는 right가 pivot이 된다
        if (right < k)
            start = right + 1;
        else
            end = right - 1;
    } while (right != k);

    return arr[right];
}

int main(int argc, char const *argv[])
{
    return 0;
}