#include <fstream>
#include <iostream>

/** 백준_2167 2차원 배열의 합 ( https://www.acmicpc.net/problem/2167 )
 *  * Dynamic Porgramming ==> prefix sum technition
 *  * 부분 합 기법을 이용하여 동적 계획법 적용한다
 *  * REVIEW find the prefix sum technition
 */

using namespace std;

int dp[300][300];

int solution(int **arr, int i, int j, int x, int y)
{
    int answer = 0;

    cout << i << j << x << y << endl;

    for (int a = i; a <= x; a++)
    {
        for (int b = j; b <= y; b++)
        {
            answer += arr[a][b];
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    int K, N, M, a, b, c, d;
    cin >> N >> M;

    int **arr = new int *[N+1];
    for (int i = 1; i <= N; i++)
    {
        arr[i] = new int[M+1];
        for (int j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
        }
    }

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> a >> b >> c >> d;

        cout << solution(arr, a, b, c, d) << endl;
    }

    return 0;
}