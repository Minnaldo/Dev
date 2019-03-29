#include <fstream>
#include <iostream>

/** 히스토그램에서 가장 큰 직사각형 백준_6549 ( https://www.acmicpc.net/problem/6549 )
 *  * 자료형 크기에 따른 문제가 생긴다
 *  REVIEW 19.03.27 need to review
 */

using namespace std;

long long arr[100000];

long long max(long long &a, long long &b) { return a > b ? a : b; }
long long min(long long &a, long long &b) { return a < b ? a : b; }

long long histo(long long *arr, int start, int end)
{
    if (start == end)
        return 0;
    if (start + 1 == end)
        return arr[start];

    int mid = (start + end) / 2;
    long long ret = max(histo(arr, start, mid), histo(arr, mid, end)); // 양쪽 구간의 사각형의 크기

    // 걸쳐있는 구간의 넓이
    long long width = 1, height = arr[mid], left = mid, right = mid;

    while (right - left + 1 < end - start)
    {
        // 확장시 높이는 줄어든다
        int p = left > start ? min(height, arr[left - 1]) : -1;     // 왼쪽으로 확장시 높이
        int q = right < end - 1 ? min(height, arr[right + 1]) : -1; // 오른쪽으로 확장 시 높이

        if (p >= q)
        {
            height = p;
            left--;
        }
        else
        {
            height = q;
            right++;
        }
        long long tmp = (++width) * height;
        ret = max(ret, tmp);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    while (true)
    {
        long long ans = 0, n;
        scanf("%d", &n);

        if (n == 0)
            break;
        else
        {
            for (int i = 0; i < n; i++)
                scanf("%d", &arr[i]);

            printf("%lld\n", histo(arr, 0, n));
        }
    }
    return 0;
}