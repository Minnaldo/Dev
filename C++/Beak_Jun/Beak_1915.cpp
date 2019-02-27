#include <iostream>
#include <string>

/** 가장 큰 정사각형 백준_1915 ( https://www.acmicpc.net/problem/1915 )
 *  * 대각선 길이를 구한다 --> dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
 *  * 대각선의 길이에 제곱 --> 사각형의 넓이
 *  * 우측 하단을 끝으로 하기 위해, 위, 왼쪽 위, 왼쪽의 값중 최솟값에 1을 더해 현재 칸에 저장하면 최대 크기 정사각형의 제곱근이 만들어진다.
 *  * 배열의 값이 0이 아닐 때에만 해당 계산을 하면, 쓸모없는 계산을 줄일 수 있다. ==> 가지치기
 *  NOTE sqrt, squre,
 */

using namespace std;

int N, M, dp[1001][1001];

int min(int &a, int &b) { return a < b ? a : b; }

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> N >> M;

    string str = "";

    int **arr = new int *[N + 1];
    for (int i = 1; i <= N; i++)
    {
        arr[i] = new int[M + 1];
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            arr[i][j + 1] = str[j] - '0';
        }
    }

    int answer = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (arr[i][j] == 1)
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;

            answer = answer > dp[i][j] ? answer : dp[i][j];
        }
    }

    // answer = 정사각형 크기의 제곱근이므로 이를 제곱해주어야 한다.
    cout << (answer * answer) << endl;
    return 0;
}