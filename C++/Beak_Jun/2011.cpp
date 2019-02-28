#include <iostream>
#include <string>

/** 암호 코드 백준_2011 ( https://www.acmicpc.net/problem/2011 )
 *  * 재귀함수를 이용
 *  * 2자리 수를 사용하여 문자를 나타내는 경우, 1자리 수를 사용하여 문자를 나타내는 경우
 *  * TODO
 */

using namespace std;

int dp[5001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie();
    int N;
    cin >> N;

    string str = to_string(N); // 문자열 전처리
    int size = str.size();

    dp[0] = 1; // 왜 0번째에 1을 넣어줘야 할까?? REVIEW

    for (int i = 1; i <= size; i++)
    {
        int tmp = str[i - 1] - '0';
        if (tmp != 0)
        {
            dp[i] = (dp[i - 1] + dp[i]) % 1000000;
        }

        int tmp1 = ((str[i - 2] - '0') * 10) + (str[i - 1] - '0');
        if (9 < tmp1 && tmp1 <= 26)
        {
            dp[i] = (dp[i - 2] + dp[i]) % 1000000;
        }
    }

    cout << dp[size] % 1000000 << endl;

    return 0;
}