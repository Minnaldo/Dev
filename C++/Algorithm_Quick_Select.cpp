/**
 * * 퀵정렬/Quick Select
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