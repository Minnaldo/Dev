#include <algorithm>
#include <iostream>
#include <string>

/** 단어 공부 백준_1157 ( https://www.acmicpc.net/problem/1157 )
 *  ? 현재 시간 44ms --> 더 줄일 수 있는 방법은?
 */

using namespace std;

int dp[26];

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;

    transform(str.begin(), str.end(), str.begin(), ::toupper);

    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        int tmp = str[i] - 'A';
        dp[tmp]++;
    }

    int answer = 0, tmpVal = dp[0];
    for (int i = 1; i < 26; i++)
    {
        if (tmpVal < dp[i])
        {
            answer = i;
            tmpVal = dp[i];
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (tmpVal == dp[i] && i != answer)
        {
            cout << "?" << endl;
            return 0;
        }
    }

    cout << (char)(answer + 'A') << endl;

    return 0;
}