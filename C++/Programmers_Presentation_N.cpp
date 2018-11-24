#include <iostream>

using namespace std;

/** Programmers N으로 표현 (https://programmers.co.kr/learn/courses/30/lessons/42895)
 * * Dynamic Programming Problem
 */

//N 사용 횟수를 dp배열에 저장
int dp[32000], numCnt;

int min(int a, int b)
{
    return a < b ? a : b;
}

int solution(int N, int number)
{

    for (int i = 1; i <= N; i++)
    {
        dp[i] = min(dp[i], dp[i - N]) + 1; // '+' case
        dp[i] = min(dp[i], dp[i / N]) + 1; // '*' case
        dp[i] = min(dp[i], dp[i + N]) + 1; // '-' case
        dp[i] = min(dp[i], dp[i * N]) + 1; // '/' case

        number -= dp[i];

        if(number == 0)
        {
            return dp[i];
        }
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}