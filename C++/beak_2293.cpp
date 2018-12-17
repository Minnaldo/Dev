#include <fstream>
#include <iostream>
#include <sstream>

/**
 *  * dp[n] = n을 만들수 있는 경우의 수
 */

using namespace std;

int dp[101], cnt, num;

int solution(int k, int *arr)
{
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            if (i - arr[j] >= 0)
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
        num = n;
        fs >> K;
        int *arr = new int[n + 1];
        for (int i = 1; i <= n; i++)
        {
            fs >> tmp;
            arr[i] = tmp;
        }

        // for(int i = 1; i<=n; i++)
        // {
        //     for(int j = 1; j<=n; j++)
        // }

        cout << solution(K, arr) << "\n";
    }

    cout << cnt << endl;
    return 0;
}