#include <iostream>

/** 퇴사 백준_14501 (https://www.acmicpc.net/problem/14501)
 *
 */

using namespace std;

int dp[2][15];

int max(int a, int b)
{
    return a > b ? a : b;
}

int solution(int n, int **arr)
{
    for (int i = 1; i <= n; i++)
    {
    }
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    int **arr = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        arr[i] = new int[N + 1];
    }
    for (int j = 1; j <= N; j++)
    {
        int T, P;
        cin >> T >> P;
        arr[0][j] = T;
        arr[1][j] = P;
    }

    cout << solution(N, arr) << endl;
    return 0;
}