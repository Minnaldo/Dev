#include <fstream>
#include <iostream>

/** 동전2 백준_2294 (https://www.acmicpc.net/problem/2294)
 *  * dp[n] = n을 나타내는데 사용한 동전의 갯수 중 작은 갯수
 *  * 동전을 최대한 적게 사용하려면 가장 큰 가치의 동전부터 사용하면 된다
 *  * 불가능한 경우는 언제? ==> 동전의 가치가 나타낼 가치보다 클 때?
 */

using namespace std;

int dp[10001];

int min(int a, int b)
{
    return a < b ? a : b;
}

int solution(int n, int k, int *arr)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] <= k)
        {
            cnt++;
        }
    }

    if (cnt > 0)
    {

        for (int i = 1; i <= k; i++)
        {
            for (int j = 2; j <= n; j++)
            {
                if (i >= arr[j])
                {
                    dp[i] = dp[i - arr[1]] + 1;
                    dp[i] = min(dp[i], dp[i - arr[j]] + 1);
                }
            }
        }

        return dp[k];
    }
    else
    {
        return (-1);
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int n, K, tmp;

    fstream fs("input.txt");

    fs >> n >> K;
    int *arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        fs >> tmp;
        arr[i] = tmp;
    }
    //pre-processing
    dp[0] = -1;
    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == arr[j])
                dp[i] = 1;
        }
    }

    cout << solution(n, K, arr) << "\n";
    return 0;
}