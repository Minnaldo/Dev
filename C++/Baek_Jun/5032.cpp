#include <iostream>

/** 탄산 음료 백준_5032 ( https://www.acmicpc.net/problem/5032 )
 *  * 음료를 먹을수록 병이 계속 생김 <-- Point
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int e, f, c, ans;
    scanf("%d %d %d", &e, &f, &c);

    ans = (e + f) / c;
    int tmp = ans + ((e + f) % c);
    while (tmp >= c)
    {
        ans += (tmp / c);
        tmp = (tmp % c) + (tmp / c);
    }

    printf("%d\n", ans);

    return 0;
}