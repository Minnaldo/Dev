#include <iostream>

using namespace std;

/** 백준 타일링_1793 (https://www.acmicpc.net/problem/1793)
 *  * Big Integer를 구현하여 이를 이용해 출력해야함, 이용하지 않을 시 오버플로 발생
 */

long long dp[251];

long long solution(int n)
{
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + (2 * dp[i - 2]);
    }

    return dp[n];
}

int main(int argc, char const *argv[])
{
    dp[1] = 1;
    dp[2] = dp[1] + 2;
    int n;
    while (cin >> n)
    {
        cout << solution(n) << endl;
    }
    return 0;
}