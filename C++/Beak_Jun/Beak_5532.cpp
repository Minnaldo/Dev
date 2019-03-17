#include <iostream>

/* 방학 숙제 백준_5532 ( https://www.acmicpc.net/problem/5532 )
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int L, A, B, C, D, ans;
    scanf("%d %d %d %d %d", &L, &A, &B, &C, &D);

    int tmp = A / C, tmp2 = B / D;

    if (A % C > 0)
        tmp++;
    if (B % D > 0)
        tmp2++;

    ans = L - (tmp > tmp2 ? tmp : tmp2);
    printf("%d\n", ans);

    return 0;
}