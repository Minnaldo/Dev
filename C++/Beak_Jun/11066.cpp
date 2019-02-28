#include <fstream>
#include <iostream>

/**
 *  * 모든 과정에서 생성되는 임시파일 크기의 합의 최소를 구하는 문제
 *  * 바로 옆의 파일만 합칠 수 있다.
 */

using namespace std;

long long dp[10001][10001];

int min(int &a, int &b) { return a < b ? a : b; }

long long solution(int *arr, int n)
{
    int answer = 0;

    for (int j = 1; j < n; j++)
    {
        // 파일끼리 합쳤을 때, when merge between the file size
        dp[j][1] = arr[j] + arr[j + 1];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[j][i] = min(dp[j][i] + arr[j - 1], dp[j][i] + arr[j + 1]);
            dp[j][i] = min(dp[j][i] + arr[j + 2], dp[j][i] + arr[j - 1]);
        }
    }

    answer = dp[2][n];
    for (int i = 1; i <= n; i++)
    {
        if (answer > dp[i][n] && dp[i][n] != 0)
            answer = dp[i][n];
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    ios::sync_with_stdio(false);
    int T, N;
    fs >> T;

    for (int i = 0; i < 1; i++)
    {
        fs >> N;

        int *arr = new int[N + 1];
        for (int j = 1; j <= N; j++)
        {
            fs >> arr[j];
            dp[j][0] = arr[j];
        }

        cout << solution(arr, N) << endl;
    }
    return 0;
}