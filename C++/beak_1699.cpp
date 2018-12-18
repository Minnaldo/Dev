#include <iostream>

using namespace std;

/** 백준 제곱수의 합_1699 (https://www.acmicpc.net/problem/1699)
 *  * 점화식 : dp[n] = n^2로 T를 만들때 필요한 n^2의 갯수
 *  * 현재의 제곱수의 최소값을 위해서 이전의 최소값을 이용하여 최소값을 만든다.
 *  * 검색의 범위는 1부터 j*j <= i
 *  * j의 최대값만으로 하면 예외 조건이 발생 할 수 있음 --> 1~j의 최대값까지 전부 비교해야함 (27번 라인 if문)
 *  REVIEW
 */

int dp[100001];

int min(int a, int b)
{
    return a < b ? a : b;
}

//dp[n]에서 1~j
int solution(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (dp[i] > dp[i - j * j] + 1 || dp[i] == 0)    // 예외조건 판단문
            {
                dp[i] = dp[i - j * j] + 1;
            }
        }
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T; // 142 --> 3
    cout << solution(T) << endl;
    return 0;
}