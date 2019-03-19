#include <iostream>

/** 과제 안 내신 분..? 백준_5597 ( https://www.acmicpc.net/problem/5597 )
 *
 */

using namespace std;

bool arr[31];

int main(int argc, char const *argv[])
{
    int n;
    for (int i = 0; i < 28; i++)
    {
        scanf("%d", &n);
        arr[n] = true;
    }

    for (int i = 1; i <= 30; i++)
    {
        if (!arr[i])
            printf("%d\n", i);
    }
    return 0;
}