#include <iostream>

/** 상자넣기 백준_1965 ( https://www.acmicpc.net/problem/1965 )
 *  ! 항상 마지막값이 최대값은 아니다
 *
 */

using namespace std;

int dp[1001];

int main(int argc, char const *argv[])
{
    int N, answer;
    cin >> N;
    int *arr = new int[N + 1];
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    dp[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    answer = dp[1];
    for (int i = 2; i <= N; i++)
    {
        if (answer < dp[i])
            answer = dp[i];
    }
    cout << answer << endl;
    return 0;
}