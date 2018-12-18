#include <fstream>
#include <iostream>
#include <sstream>

/** 동전1 백준_2293 (https://www.acmicpc.net/problem/2293)
 *  * arr[1]로 나타낼 수 있는 경우의 수를 계산 후, arr[2]. arr[3], ... , arr[n]으로 나타낼 수 있는 경우의수를 구하여 모두 더하면 답이 나온다
 *  NOTE anothor solution
 */

using namespace std;

int dp[10001];

// arr[1]로 나타낼 수 있는 경우의 수를 계산 후, arr[2]. arr[3], ... , arr[n]으로 나타낼 수 있는 경우의수를 구하여 모두 더하면 답이 나온다
int solution(int n, int k, int *arr)
{
    for (int j = 1; j <= n; j++)    // n = 동전의 갯수
    {
        for (int i = 1; i <= k; i++)    // k = 나타내야할 가치
        {
            if (i >= arr[j])
                dp[i] = dp[i] + dp[i - arr[j]];
        }
    }

    return dp[k];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    // string str = "3 10 1 2 5";   //10
    // stringstream ss;
    // ss.str(str);
    ifstream fs("input.txt"); //10
    int n, K, tmp;

    while (fs >> n)
    {
        fs >> K;
        int *arr = new int[n + 1];
        for (int i = 1; i <= n; i++)
        {
            fs >> tmp;
            arr[i] = tmp;
        }
        dp[0] = 1;
        cout << solution(n, K, arr) << "\n";
    }
    return 0;
}