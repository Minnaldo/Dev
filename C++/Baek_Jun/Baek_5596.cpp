#include <iostream>

/** 시험 점수 백준_5596 ( https://www.acmicpc.net/problem/5596 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int S = 0, tmp, T = 0, ans;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &tmp);
        S += tmp;
    }
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &tmp);
        T += tmp;
    }

    ans = (S == T ? S : (S > T ? S : T));
    printf("%d\n",ans);

    return 0;
}