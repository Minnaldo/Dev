#include <vector>
#include <iostream>

using namespace std;

int dp[501][501];

int max(int a, int b)
{
    return a > b ? a : b;
}

int solution(vector<vector<int>> triangle)
{
    int n = triangle.size();

    dp[0][0] = triangle[0][0];
    dp[1][0] = triangle[1][0] + dp[0][0];
    dp[1][1] = triangle[1][1] + dp[0][0];

    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            dp[i][j] = max(triangle[i][j] + dp[i - 1][j-1], triangle[i][j] + dp[i-1][j]);
        }
    }

    int r = triangle[n - 1].size();
    int answer = dp[n - 1][0];

    for (int i = 1; i <= r - 1; i++)
    {
        answer = max(answer, dp[n - 1][i]);
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = {{{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}};
    cout << solution(arr) << endl;
    return 0;
}