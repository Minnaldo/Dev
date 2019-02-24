#include <iostream>
#include <string>

/** LCS (Longest Common Subsequence) 백준_9251 ( https://www.acmicpc.net/problem/9251 )
 *  * 노트에 정리 필요 TODO
 *  TODO find that concept about the LCS
 *  Ref 1) https://mygumi.tistory.com/126, Ref 2) https://twinw.tistory.com/126
 */

using namespace std;

int dp[1001][1001];

int max(int &a, int &b)
{
    return a > b ? a : b;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    string str1, str2;
    cin >> str1 >> str2;

    int str1_Size = str1.size(), str2_Size = str2.size(), answer = 0;

    for (int i = 1; i <= str2_Size; i++)
    {
        for (int j = 1; j <= str1_Size; j++)
        {
            if (str1[j - 1] == str2[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    for (int i = 0; i <= str1_Size; i++)
    {
        if (answer < dp[str2_Size][i])
            answer = dp[str2_Size][i];
    }
    cout << answer << endl;

    return 0;
}