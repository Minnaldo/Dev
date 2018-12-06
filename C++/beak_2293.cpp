#include <iostream>
#include <sstream>

using namespace std;

int dp[101];

// long long combination(int n, int r)
// {
//     long long **combination = new long long *[n + 1];
//     for (int i = 0; i <= n; i++)
//     {
//         combination[i] = new long long[r + 1];
//     }
//     combination[1][1] = 1;

//     // 100개에서 r개를 뽑는 경우의 수 ==> i개에서 j개를 뽑는 경우의 수
//     for (int i = 2; i <= n; i++)
//     {
//         for (int j = 1; j <= r; j++)
//         {
//             combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
//         }
//     }
//     long long answer = combination[n][r];

//     for (int i = 0; i <= n; i++)
//     {
//         delete[] combination[i];
//     }
//     delete[] combination;

//     return answer;
// }

int solution(int k, int *arr, int n)
{
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i - arr[j]) >= 0)
            {
                dp[i] += dp[i - arr[j]] + 1;
            }
        }
        cout<<"dp "<<dp[i]<<endl;
    }

    return dp[k];
}

int main(int argc, char const *argv[])
{
    string str = "3 10 1 2 5";
    stringstream ss;
    ss.str(str);
    int n, K;
    ss >> n >> K;

    int *arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        ss >> tmp;
        arr[i] = tmp;
    }

    cout << solution(K, arr, n) << endl;
    return 0;
}