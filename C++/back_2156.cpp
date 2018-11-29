#include <iostream>
#include <sstream>

/** 포도주 시식, 백준_2156 (https://www.acmicpc.net/problem/2156)
 *  * 고려 사항 : 1) 내가 현재의 포도주를 먹지 않았을 경우, 2) 현재의 포도주를 마시고 이전꺼를 안마신 경우, 3) 현재의 포도주와 이전의 포도주를 마신 경우
 *  * 1) 0번 마신경우 ==> dp[n] = dp[n-1] ( 이전 잔까지가 2번연속 마신 경우 )
 *  * 2) 1번 연속 마신 경우 ==> dp[n] = arr[n] + dp[n-2]
 *  * 3) 2번 연속 마신 경우 ==> dp[n] = arr[n] + arr[n-2]+ dp[n-3]
 *  NOTE
 */

using namespace std;

int dp[10001];

int max(int a, int b)
{
    return a > b ? a : b;
}

int solution(int n, int *arr)
{
    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(arr[i] + arr[i - 1] + dp[i - 3], arr[i] + dp[i - 2]);
        dp[i] = max(dp[i], dp[i - 1]);
        cout << dp[i] << endl;
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    // correct: 31, wrong : 29
    stringstream ss;
    string str = "8 7 7 0 5 7 7 0 3";
    ss.str(str);

    int n;
    ss >> n;

    int *arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        ss >> tmp;
        arr[i] = tmp;
    }
    arr[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[2] + arr[1];
    cout << solution(n, arr) << endl;
    return 0;
}