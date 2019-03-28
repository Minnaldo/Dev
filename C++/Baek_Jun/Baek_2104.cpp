#include <iostream>

/** 부분배열 고르기 백준_2104 ( https://www.acmicpc.net/problem/2104 )
 *  REVIEW
 *  NOTE  this algorithm spent  Nlog N Big-O notation
 *  NOTE  it has the way to solve in N Big-O notation
 */

using namespace std;

long long arr[100000], psum[100000];

long long min(long long &a, long long &b) { return a < b ? a : b; }
long long max(long long &a, long long &b) { return a > b ? a : b; }

long long partialArray(long long start, long long end)
{
    if (start == end) // 원소 한개만 선택했을 경우
        return arr[start] * arr[start];

    int mid = (end + start) / 2; // <==> (end+start) >> 1; 같은표현
    long long ret = max(partialArray(start, mid), partialArray(mid + 1, end));

    long long left = mid, right = mid + 1;
    long long Min = min(arr[left], arr[right]); // 위에서 한개만 선택했을 경우가 나옴, 그러므로 최소 2개 고를 경우를 생각해야함
    // 그러므로, 가운데부터 확장해나가는 방법을 취한다
    ret = max(ret, (arr[left] + arr[right]) * Min);
    // 양쪽 분할 구간에 걸치는 범위의 판단
    while (start < left || right < end)
    {
        if (start == left || (right < end && arr[right + 1] > arr[left - 1]))
        {
            right++;
            Min = min(Min, arr[right]);
        }
        else
        {
            left--;
            Min = min(Min, arr[left]);
        }
        // psum[left -1] 인 이유 --> left까지 포함해야함 (left ~ rigt 범위의 값을 구해야 하기 때문에)
        ret = max(ret, Min * (psum[right] - (left == 0 ? 0 : psum[left - 1])));
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    long long n;
    scanf("%lld", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        psum[i] = arr[i] + (i == 0 ? 0 : psum[i - 1]);
    }

    printf("%lld\n", partialArray(0, n));
    return 0;
}