#include <iostream>

/** 피보나치 수 3 백준_2749 ( https://www.acmicpc.net/problem/2749 )
 *
 */

using namespace std;

long long arr[1500001];

int main(int argc, char const *argv[])
{
    long long n;
    scanf("%lld", &n);

    arr[0] = 0;
    arr[1] = 1;

    int p = 1500000;
    int idx = n % p;
    for (int i = 2; i <= idx; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
    }

    long long ans = arr[idx] % 1000000;
    printf("%lld\n", ans);

    return 0;
}