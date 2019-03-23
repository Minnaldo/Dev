#include <iostream>

/** 이항 계수 1 백준_11050 ( https://www.acmicpc.net/problem/11050 )
 *  * 이항 계수 (N, K) = (N-1,K) + (N-1, K-1)
 */

using namespace std;

int func(int n, int k)
{
    if (n == k || k == 0)
        return 1;
    return func(n - 1, k) + func(n - 1, k - 1);
}

int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);

    printf("%d\n", func(n, k));

    return 0;
}