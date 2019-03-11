#include <iostream>
#include <string>

/** 숫자의 개수 백준_2577 ( https://www.acmicpc.net/problem/2577 )
 *
 */

using namespace std;

int dp[10];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;

    string str = to_string(a * b * c);
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        dp[str[i] - '0'] += 1;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << dp[i] << endl;
    }

    return 0;
}