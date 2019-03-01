#include <fstream>
#include <iostream>

/** 파일 합치기 백준_11066 ( https://www.acmicpc.net/problem/11066 )
 *  REVIEW
 *  * 모든 과정에서 생성되는 임시파일 크기의 합의 최소를 구하는 문제
 *  * 파일 + 파일, 파일 + 임시파일( or 임시파일 + 파일 ), 임시파일 + 임시파일
 *  https://sexycoder.tistory.com/92
 */

using namespace std;

long long dp[10001][10001];
int psum[501];
int *arr;

int min(int &a, int &b) { return a < b ? a : b; }

long long solution(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tmp = j + i; //?? 왜 이렇게 설정을 하는거지??
            dp[j][tmp] = INT32_MAX;

            for (int k = j; k < tmp; k++)
            {
                dp[j][tmp] = min(dp[j][tmp], dp[j][k] + dp[k + 1][tmp] + psum[tmp] - psum[j - 1]);
            }
        }
    }

    return dp[1][n];
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    ios::sync_with_stdio(false);

    int T, N;
    fs >> T;

    for (int i = 0; i < T; i++)
    {
        fs >> N;
        arr = new int[N + 1];
        arr[0] = 0;
        for (int j = 1; j <= N; j++)
        {
            fs >> arr[j];
            psum[j] = psum[j - 1] + arr[j]; // make partial sum
        }

        cout << solution(N) << endl;
    }

    return 0;
}