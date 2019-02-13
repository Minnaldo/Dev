#include <iostream>

/**
 *  * quick_sort의 partition부분의 개념을 이용하여 K번째의 element를 찾는 알고리즘
 *  * 시간복잡도 O(N), 상수 시간
 *  * 정렬 후 K번째 인덱스를 찾을 경우, 정렬에서 최악의 경우 O(N^2)의 시간이 걸려 quick_selection 알고리즘에 비해 더 오랜 시간이 걸릴 수 있다
 */

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// 피벗이 배열의 왼쪽 일 때의 퀵 정렬 알고리즘의 partition함수 로직을 이용한 quick_selection
// pivot idx == last element of array
void partition(int arr[], int start, int end, int K)
{
    int left = start+1, right = end;
    int pivot = start;

    while(right != K)
    {
        // quick_sort의  partition 부분의 로직과 같다
        while( left < right )
        {
            while(arr[left] > arr[pivot])   // arr[pivot]보다 큰 arr[left]의 인덱스를 찾을때까지 인덱스값 증가시킨다
            left++;
            while(arr[right]<arr[pivot])    // arr[pivot]보다 작은 arr[right]의 인덱스를 찾을때까지 인덱스값 감소시킨다
            right--;

            // 배열의 크기가 2 이상일 때
            if(left < right)
                swap(arr[left],arr[right]);
        }

        // 배열의 크기가 2 미만일때
        swap(arr[start], arr[right]);

        if(right < K)
        // pivot 기준 오른쪽
        pivot = right+1;
        else
        // pivot 기준 왼쪽
        end = pivot - 1;

    }   // end of while

    return arr[right];
}

int main()
{

}