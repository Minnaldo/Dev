#include <iostream>

/** 피보나치 수 백준_2748 ( https://www.acmicpc.net/problem/2748 )
 *
 */

using namespace std;

long long arr[91];

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    printf("%lld\n", arr[n]);

    return 0;
}