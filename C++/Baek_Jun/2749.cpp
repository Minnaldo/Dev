#include <iostream>

using namespace std;

int arr[10e18];

int main(int argc, char const *argv[])
{
    long long n;
    scanf("%lld", &n);

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
    }
    printf("%d\n", arr[n]%1000000);

    return 0;
}