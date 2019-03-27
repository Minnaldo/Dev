#include <fstream>
#include <iostream>

/**
 *  NOTE time out
 *  * 시간을 줄이려면 어떻게 해야할까?
 */

using namespace std;

long long arr[100000];

long long min(long long &a, long long &b) { return a < b ? a : b; }
long long max(long long &a, long long &b) { return a > b ? a : b; }

long long partialArray(long long start, long long end)
{
    if (start == end)
        return arr[start] * arr[start];

    int mid = (end + start) / 2;
    // 나눠진 부분
    long long ret = max(partialArray(start, mid), partialArray(mid + 1, end));

    long long mul = 1000001, mul2 = 1000001;
    long long sum = 0, sum2 = 0;

    // 겹치는 부분 판단
    for (int i = start; i < end; i++)
    {
        for (int j = i; j < end; j++)
        {
            sum += arr[j];
            mul = min(mul, arr[j]);
        }
        for (int j = end - 1; j > i; j--)
        {
            sum2 += arr[j];
            mul2 = min(mul2, arr[j]);
        }
        ret = max(sum * mul, sum2 * mul2);
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    long long n;
    // scanf("%lld", &n);
    fs >> n;

    for (int i = 0; i < n; i++)
        // scanf("%lld", &arr[i]);
        fs >> arr[i];

    long long ans = partialArray(0, n);
    printf("%lld\n", ans);
    return 0;
}