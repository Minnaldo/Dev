#include <fstream>
#include <iostream>

using namespace std;

long long arr[100000];

long long min(long long &a, long long &b) { return a < b ? a : b; }
long long max(long long &a, long long &b) { return a > b ? a : b; }

long long partialArray(long long start, long long end)
{
    if (start == end)
        return arr[start] * arr[start];

    // 양쪽에서 범위를 줄여가며 값을 가져온다
    long long ret = max(partialArray(start + 1, end), partialArray(start, end - 1));

    long long mul = 1000001, sum = 0;
    for (int i = start; i < end; i++)
    {
        sum += arr[i];
        mul = min(mul, arr[i]);
    }

    ret = max(ret, sum * mul);

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

    printf("%lld\n", partialArray(0, n));
    return 0;
}