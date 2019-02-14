#include <iostream>
#include <string>
#include <math.h>

/**
 *  * 곱하기의 수를 먼저 예측하는 것이 중요하다.
 */

using namespace std;

int answer;

void funct(int n, int starCount, int plusCount)
{
    if ((log10(n) / log10(3)) < starCount) // log10(n) / log10(3) : '*'가 나올수 있는 최소 수
    {
        return;
    }

    if (n > 3)
    {
        funct(n - 1, starCount, plusCount + 1);
        funct(n / 3, starCount + 1, plusCount);
    }
    else if (n == 3)
    {
        answer++;
        return;
    }
}

int solution(int n)
{
    answer = 0;

    funct(n - 2, 1, 0);

    return answer;
}

int main(int argc, char const *argv[])
{
    // int n = 15;
    // int n = 41;
    // int n = 2000000000;  //  segfault
    int n = 2147483647; //  segfault
    cout << solution(n) << endl;
    return 0;
}