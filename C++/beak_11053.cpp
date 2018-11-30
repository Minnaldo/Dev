#include <iostream>
#include <sstream>

/** 가장 긴 증가하는 부분 수열 백준_11053 (https://www.acmicpc.net/problem/11053)
 *  ? 처음에 arr[n+1]보다 큰 값이 나왔는데, arr[n+1]부터의 증가수열이 더길다면?? (현 코드의 반례)
 */

using namespace std;

int dp[1001], cnt;

int solution(int n, int *arr)
{
    for (int i = 1; i <= n; i++)
    {
        if(dp[i-1] < arr[i])
        {
            dp[i] = arr[i];
            cnt++;
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    // string str="6 10 20 10 30 20 50";
    string str2 = "5 1 2 3 2 3";
    stringstream ss;
    ss.str(str2);
    int n;
    ss >> n;

    int *arr = new int[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        ss >> tmp;
        arr[i] = tmp;
    }


    cout << solution(n, arr) << endl;
    return 0;
}