#include <iostream>

using namespace std;

/** 백준 제곱수_1699 (https://www.acmicpc.net/problem/1699)
 *  TODO 반례체크
 *  점화식 : dp[n] = n^2로 T를 만들때 필요한 n^2의 갯수
 *  * 동전 교환 알고리즘을 이용하면 풀 수 있을까?
 */

int dp[100001];

int min(int a, int b)
{
    return a < b ? a : b;
}

int solution(int n, int *arr)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = arr[i]; j <= n; j++)
        {
            dp[i] = min(dp[i - j] + 1, dp[j]);
        }
        cout << dp[i] << endl;
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T; // 142 --> 3
    // int T = 142;
    // int T = 43; // 3
    int *arr = new int[T + 1];
    //전처리
    for (int i = 1; i <= T; i++)
    {
        dp[i] = i;
        arr[i] = i * i;
    }
    cout << solution(T, arr) << endl;
    return 0;
}