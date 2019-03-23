#include <iostream>

/** 피보나치 수 백준_2747 ( https://www.acmicpc.net/problem/2747 )
 *
 */

using namespace std;

int arr[45];

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
    printf("%d\n", arr[n]);

    return 0;
}