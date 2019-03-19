#include <algorithm>
#include <iostream>

/** 직각삼각형 백준_4153 ( https://www.acmicpc.net/problem/4153 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[3];

    while (true)
    {
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
            break;

        sort(arr, arr + 3);
        if ((arr[0] * arr[0]) + (arr[1] * arr[1]) == (arr[2] * arr[2]))
            printf("right\n");
        else
            printf("wrong\n");
    }

    return 0;
}