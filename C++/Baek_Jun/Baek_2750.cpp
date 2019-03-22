#include <algorithm>
#include <iostream>

/** 수 정렬하기 백준_2750 ( https://www.acmicpc.net/problem/2750 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);

    return 0;
}