#include <fstream>
#include <iostream>

/**
 *  * 모든 과정에서 생성되는 임시파일 크기의 합의 최소를 구하는 문제
 *  * 바로 옆의 파일만 합칠 수 있다.
 *  * 파일 + 파일, 파일 + 임시파일( or 임시파일 + 파일 ), 임시파일 + 임시파일
 *  TODO i re-think for logic
 */

using namespace std;

long long dp[10001][10001];

// int min(int &a, int &b) { return a < b ? a : b; }

long long solution(int *arr, int n)
{
    int answer = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tmp = (j + 3) % n;
            dp[j][i] = min(dp[j][i - 1] + dp[j + 1][i - 1], dp[j][i] + dp[j + 1][i]);
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    ios::sync_with_stdio(false);
    int T, N;
    fs >> T;

    // 2개의 테스트 케이스를 위해 i < 1 ==> i < 2
    for (int i = 0; i < 1; i++)
    {
        fs >> N;

        int *arr = new int[N + 1];
        arr[0] = 0;
        for (int j = 1; j <= N; j++)
        {
            fs >> arr[j];
            cout << arr[j] << " ";
            dp[j][0] = arr[j];
        }
        cout << endl;

        cout << solution(arr, N) << endl;
    }
    return 0;
}