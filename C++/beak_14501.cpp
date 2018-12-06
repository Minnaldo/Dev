#include <iostream>
#include <sstream>

/** 퇴사 백준_14501 (https://www.acmicpc.net/problem/14501)
 *
 */

using namespace std;

int dp[16];

int max(int a, int b)
{
    return a > b ? a : b;
}

int solution(int n, int **arr)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < 6; j++) // j : 1~5
        {
            if (arr[0][i - j] == j && (i-j) > 0)
            {
                dp[i] = max(dp[i], dp[i-j] + arr[1][i-j]);
            }
        }

        cout<<dp[i]<<endl;
    }

    return dp[n];
}

int main(int argc, char const *argv[])
{
    string str = "7 3 10 5 20 1 10 1 20 2 15 4 40 2 200";   //45
    string str2 = "10 1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 1 10";    //55
    string str3 = "10 5 10 5 9 5 8 5 7 5 6 5 10 5 9 5 8 5 7 5 6";   //20
    stringstream ss;

    ss.str(str);


    int N;
    ss >> N;

    int **arr = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        arr[i] = new int[N + 1];
    }
    for (int j = 1; j <= N; j++)
    {
        int T, P;
        ss >> T >> P;
        arr[0][j] = T;
        arr[1][j] = P;

        // cout<<arr[0][j]<<" "<<arr[1][j]<<endl;
    }

    cout << solution(N, arr) << endl;


    return 0;
}