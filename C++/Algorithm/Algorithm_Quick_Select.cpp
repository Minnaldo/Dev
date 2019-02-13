/**
 * * 퀵정렬을 이용한 Quick Select
 * * pivot값을 설정 후, pivot보다 작으면 왼쪽, 크면 오른쪽으로 재배치
 * * 분할 정복 기법중 하나
 * kth = k번째 수
*/

int quickSelect(int arr[], int lo, int hi, int kth)
{
    int i, j;
    do
    {
        i = lo, j = hi;
        while (i < j)
        {
            while (i <= hi && arr[i] <= arr[lo]) i++;
            while (arr[j] > arr[lo]) j--;

            if (i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[lo], arr[j]);

        if (j < kth) lo = j + 1;
        else hi = j - 1;

    } while (j != kth);

    return arr[j];
}