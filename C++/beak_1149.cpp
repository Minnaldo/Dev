#include <iostream>
#include <sstream>
#include <chrono>

using namespace std;

/** 백준 온라인 RGB거리 (https://www.acmicpc.net/problem/1149)
 *  * Dynamic Programming Problem
 *  TODO : 다른 사람이 푼 문제의 점화식과 내 점화식 비교 (http://hellogohn.com/post_one255)
 */

int dp[3][1001]; // 집의 수 <= 1000

int min(int a, int b)
{
    return a < b ? a : b;
}

//동적 할당 2차원 배열 전달 받기
int solution(int n, int **arr)
{
    for (int j = 3; j <= n; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            //if문 수정 가능 할듯
            if (i == 0)
            {
                dp[i][j] = min(arr[i][j] + dp[1][j - 1] + dp[0][j - 2], arr[i][j] + dp[1][j - 1] + dp[2][j - 2]);
                dp[i][j] = min(dp[i][j], arr[i][j] + dp[2][j - 1] + dp[0][j - 2]);
                dp[i][j] = min(dp[i][j], arr[i][j] + dp[2][j - 1] + dp[1][j - 2]);
            }
            else if (i == 1)
            {
                dp[i][j] = min(arr[i][j] + dp[2][j - 1] + dp[0][j - 2], arr[i][j] + dp[0][j - 1] + dp[1][j - 2]);
                dp[i][j] = min(dp[i][j], arr[i][j] + dp[2][j - 1] + dp[0][j - 2]);
                dp[i][j] = min(dp[i][j], arr[i][j] + dp[2][j - 1] + dp[1][j - 2]);
            }
            else
            {
                dp[i][j] = min(arr[i][j] + dp[0][j - 1] + dp[1][j - 2], arr[i][j] + dp[0][j - 1] + dp[2][j - 2]);
                dp[i][j] = min(dp[i][j], arr[i][j] + dp[1][j - 1] + dp[0][j - 2]);
                dp[i][j] = min(dp[i][j], arr[i][j] + dp[1][j - 1] + dp[2][j - 2]);
            }

            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return min(dp[0][n], min(dp[1][n], dp[2][n]));
}

int main(int argc, char const *argv[])
{
    stringstream ss;
    string in_file = "3 2 2 5 2 1 5 5 1 1"; // correct answer : 4, output : 5
    string str = "3 26 40 83 49 60 57 13 89 99";
    ss.str(str);

    auto start = chrono::steady_clock::now();

    int n, tmp;
    ss >> n;
    int **arr = new int *[3];

// !배열 설정이 잘못 되었다.
    for (int i = 0; i < 3; i++)
    {
        arr[i] = new int[n+1];
        for (int j = 1; j <= n; j++)
        {
            ss >> tmp;
            arr[i][j] = tmp;
        }
    }

    dp[0][1] = arr[0][1];
    dp[1][1] = arr[1][1];
    dp[2][1] = arr[2][1];
    dp[0][2] = min(arr[0][2] + dp[1][1], arr[0][2] + dp[2][1]);
    dp[1][2] = min(arr[1][2] + dp[0][1], arr[1][2] + dp[2][1]);
    dp[2][2] = min(arr[2][2] + dp[1][1], arr[2][2] + dp[0][1]);

    for (int i = 1; i <= 2; i++)
    {
        for (int j = 0; j <3; j++)
        {
            cout << dp[j][i] << " ";
        }
        cout << endl;
    }

    cout << solution(n, arr) << endl;

    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << "Duration : " << duration.count() / 1000000.0 << " ms" << endl;
    // 동적 할당 2차원 배열 메모리 해제
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}