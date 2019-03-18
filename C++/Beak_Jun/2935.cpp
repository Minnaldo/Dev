#include <iostream>
#include <string>

/** 소음 백준_2935 ( https://www.acmicpc.net/problem/2935 )
 *  * point ==> 자리수가 매우 크므로 변수를 이용한 출력은 안됨
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    string A, B;
    char C;
    cin >> A >> C >> B;

    int tmp = A.size(), tmp1 = B.size();

    if (C == '+')
    {
        int idx = tmp > tmp1 ? tmp : tmp1;
        if (tmp == tmp1)
        {
            printf("2");
            for(int i = idx-1; i>0; i--)
                printf("0");
        }
        else
        {
            for (int i = idx; i > 0; i--)
            {
                if (i == tmp || i == tmp1)
                    printf("1");
                else
                    printf("0");
            }
        }
    }
    else
    {
        int idx = tmp > tmp1 ? ((tmp - 1) + tmp1) : (tmp + (tmp1 - 1));

        printf("1");
        for (int i = 1; i < idx; i++)
        {
            printf("0");
        }
    }
    printf("\n");
    return 0;
}