#include <iostream>

using namespace std;

int dp[1001];

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    int *arr = new int[N + 1];

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        int tmp = dp[i];
        for (int k = N; k > i; k--)
        {
            if (arr[i] > arr[k] && dp[k] < dp[i] + 1)
            {
                dp[i] = dp[k] + 1;
            }
        }
    }
    int answer = dp[1];
    for (int i = 2; i <= N; i++)
    {
        if (answer < dp[i])
            answer = dp[i];
    }

    cout << answer << endl;

    return 0;
}