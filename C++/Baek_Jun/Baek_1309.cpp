#include <iostream>

using namespace std;

/** 동물원 백준_1309 ( https://www.acmicpc.net/problem/1309 )
 *  N 번째 칸의 왼쪽에 사자가 있는 경우  ==> 다음칸에 없을 경우 + 오른쪽에 있을 경우
 *  N 번째 칸의 오른쪽에 사자가 있는 경우 ==> 다음칸에 없을 경우 + 왼쪽에 있을 경우
 *  N 번째 칸에 사자가 없는 경우 ==> 다음칸에 없을 경우 + 왼쪽에 있을 경우 + 오른쪽에 있을 경우
 *  other => dp[n] = dp[n-1] *2 + dp[n-2]   ( 규칙을 찾아 점화식을 만든 경우 )
 *  NOTE
 *  REVIEW
*/

int dp[100001][3];

int solution(int N)
{
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][0]) % 9901;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][0]) % 9901;
    }

    return (dp[N][0] + dp[N][1] + dp[N][2]) % 9901;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    cout << solution(N) << endl;
    return 0;
}