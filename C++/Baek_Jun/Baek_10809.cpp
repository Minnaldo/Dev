#include <iostream>
#include <string>

/** 알파벳 찾기 백준_10809 ( https://www.acmicpc.net/problem/10809 )
 *  * 중복글자 처리가 중요하다.
 */

using namespace std;

int dp[26];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    string str;
    cin >> str;

    fill(dp, dp + 26, -1);
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        int tmp = str[i] - 'a';
        if (dp[tmp] == -1)
            dp[tmp] = i;
        }

    for (int i = 0; i < 26; i++)
    {
        if (i < 25)
            cout << dp[i] << " ";
        else
            cout << dp[i] << endl;
    }
    return 0;
}