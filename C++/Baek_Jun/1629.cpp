#include <iostream>

/** 곱셈 백준_1629 ( https://www.acmicpc.net/problem/1629 )
 *
 */

using namespace std;

long long multiple(long long a, long long b, long long c)
{
    if (b == 0)
        return 1;
    // else if (b == 1)
    //     return a % c;

    if (b % 2 == 0)
    {
        return ((multiple(a, b / 2, c) % c) * (multiple(a, b / 2, c) % c)) % c;
    }
    else
    {
        return ((multiple(a, b - 1, c) % c) * (a % c)) % c;
    }
}

int main(int argc, char const *argv[])
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    printf("%lld\n", multiple(a, b, c) % c);

    return 0;
}