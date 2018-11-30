#include <iostream>

/** 파도반 수열 백준_9461 (https://www.acmicpc.net/problem/9461)
 *  * n번째에서 가장 긴 변의 길이
 *  * 자료형에서 걸림 int형은 overflow발생 ==> long long 자료형 사용
 */

using namespace std;

long long dp[101];

long long solution(int n)
{
    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        dp[1] = dp[2] = dp[3] = 1;
        cout << solution(n) << endl;
    }
    return 0;
}