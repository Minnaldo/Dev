#include <chrono>
#include <fstream>
#include <iostream>

/** 2차원 배열의 합 백준_2167 ( https://www.acmicpc.net/problem/2167 )
 *  * prefix sum (부분 합) 이용
 */

using namespace std;

int dp[301][301];
int N, M; // 배열의 크기를 받을 변수

int solution(int **arr, int a, int b, int c, int d)
{
    int answer = 0;

    // 원하는 구간의 합을 구하는 부분
    for (int i = a; i <= c; i++)
    {
        answer += (dp[i][d] - dp[i][b - 1]);
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    fstream fs("input.txt");
    cout << "test second" << endl;

    chrono::system_clock::time_point start = chrono::system_clock::now();

    fs >> N >> M;
    int **arr = new int *[N + 1];

    // 입력으로 주어지는 배열 생성
    for (int i = 1; i <= N; i++)
    {
        arr[i] = new int[M + 1];
        for (int j = 1; j <= M; j++)
        {
            fs >> arr[i][j];
        }
    }

    // 누적합 배열을 만드는 부분
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (j == 1)
            {
                dp[i][j] = arr[i][j];
            }
            else
            {
                dp[i][j] = dp[i][j - 1] + arr[i][j];
            }
        }
    }

    int K;
    fs >> K;

    for (int i = 0; i < K; i++)
    {
        int a, b, c, d;
        fs >> a >> b >> c >> d;
        cout << solution(arr, a, b, c, d) << endl;
    }

    chrono::system_clock::time_point end = chrono::system_clock::now();
    chrono::duration<double> durationTime = end - start;
    cout << durationTime.count() << " sec" << endl;
    return 0;
}