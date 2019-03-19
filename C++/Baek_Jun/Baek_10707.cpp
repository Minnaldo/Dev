#include <iostream>

/* 수도요금 백준_10707 ( https://www.acmicpc.net/problem/10707 )
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int A, B, C, D, P;
    scanf("%d %d %d %d %d", &A, &B, &C, &D, &P);

    int ansX = P * A, ansY = B;

    if (P > C)
    {
        ansY += (D * (P - C));
    }

    printf("%d\n", ansX < ansY ? ansX : ansY);

    return 0;
}