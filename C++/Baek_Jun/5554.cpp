#include <iostream>

/** 심부름 가는 길 백준_5554 ( https://www.acmicpc.net/problem/5554 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int a,b,c,d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int sum = a+b+c+d;

    printf("%d\n%d\n", sum/60, sum%60);

    return 0;
}