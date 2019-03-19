#include <iostream>

/** 내 학점을 구해줘 백준_10984 ( https://www.acmicpc.net/problem/10984 )
 *  * double형을 scanf or printf 에서 쓰려면 %lf로 사용
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int n;
        scanf("%d", &n);

        int tmpAns, ans = 0;
        double tmpGpa, gpa = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d %lf", &tmpAns, &tmpGpa);
            ans += tmpAns;
            gpa += (tmpGpa * tmpAns);
        }
        gpa = gpa / ans;
        printf("%d %.1lf\n", ans, (double)gpa);
    }
    return 0;
}