#include <cmath>
#include <iostream>

/** 슈퍼 마리오 백준_2851 ( https://www.acmicpc.net/problem/2851 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[10];
    int tmp, answer = 0;

    scanf("%d", &tmp);
    arr[0] = tmp;
    for (int i = 1; i < 10; i++)
    {
        scanf("%d", &tmp);
        arr[i] = arr[i - 1] + tmp;
    }

    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
            answer = arr[0];
        else if (abs(100 - arr[i - 1]) >= abs(100 - arr[i]))
        {
            answer += (arr[i] - arr[i - 1]);
        }
        else    // 더이상 먹지 않을 때 빠져나올 구문
            break;
    }

    printf("%d\n", answer);
    return 0;
}