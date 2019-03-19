#include <iostream>

/** 가장 긴 바이토닉 수열 백준_11054 ( https://www.acmicpc.net/problem/11054 )
 *  REVIEW Maybe, there is another way to solve problem
 *  * 해결 방법 : 양쪽 끝단에서 LIS를 구한 후 이둘을 합하여 구한다
 */

using namespace std;

int dp[1001];
int dp2[1001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    int *arr = new int[N + 1];
    int *tmpArr = new int[N + 1];
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        dp[i] = 1;
        dp2[i] = 1;
    }

    // LIS의 O(N^2) 방법에서 dp값을 유지하는 이유를 생각해보자
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }

    for (int i = N; i >= 1; i--)
    {
        for (int k = N; k >= i; k--)
        {
            if (arr[k] < arr[i] && dp2[i] < dp2[k] + 1)
            {
                dp2[i] = dp2[k] + 1;
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        tmpArr[i] = dp[i] + dp2[i] - 1;
        if (answer < tmpArr[i])
            answer = tmpArr[i];
    }

    cout << answer << endl;
    return 0;
}