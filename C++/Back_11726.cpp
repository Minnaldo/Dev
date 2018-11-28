#include <iostream>

/** 2 x n 타일링 백준_11726 (https://www.acmicpc.net/problem/11726)
 *  * Success, 자료형의 크기로 인한 음수값이 나오는 경우 생김 ex) n = 92
 *  ! 다른사람의 설명을 봐서 추가적인 공부가 필요할듯 NOTE
 */
using namespace std;

long long dp[1000];

long long solution(int n)
{
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    return dp[n] % 10007;
}

int main(int argc, char const *argv[])
{
    int n = 92;
    // cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    cout << solution(n) << endl;

    return 0;
}