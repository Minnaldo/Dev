#include <iostream>
#include <sstream>

/** 연속합 백준_1912 (https://www.acmicpc.net/problem/1912)
 *  * 음수를 더하여도 최대가 될 수있는 경우가 생김
 */

using namespace std;

int dp[100001];

int max(int a, int b)
{
    return a > b ? a : b;
}

int solution(int n, int *arr)
{
    for (int i = 1; i <= n; i++)
    {
        // if(dp[i-1] > (dp[i-1] + arr[i]))
        // {
        //     dp[i] = max(arr[i], dp[i] +arr[i]);
        // }
        // else
        // {
        //     dp[i] = dp[i-1]+arr[i];
        // }

        dp[i] = max(dp[i-1], dp[i-1]+arr[i]);
        // dp[i] = max()
        cout << dp[i] << " ";
    }
    cout << endl;
    return max(dp[n], dp[n - 1]);
}

int main(int argc, char const *argv[])
{
    string str = "10 10 -4 3 1 5 6 -35 12 21 -1";
    stringstream ss;
    ss.str(str);

    int T;
    ss >> T;

    int *arr = new int[T + 1];
    for (int i = 1; i <= T; i++)
    {
        int tmp;
        ss >> tmp;
        arr[i] = tmp;
    }
    cout << solution(T, arr) << endl;
    return 0;
}