#include <iostream>
#include <string>

/** 암호 코드 백준_2011 ( https://www.acmicpc.net/problem/2011 )
 *  * 재귀함수를 이용
 *  * 2자리 수를 사용하여 문자를 나타내는 경우, 1자리 수를 사용하여 문자를 나타내는 경우
 *  * TODO
 */

using namespace std;

int dp[5001];

int solution(string str, int size, int idx, int flag)
{
    if (idx > size)
        return 0;

    if (size == idx)
        return 1;

    if (flag == 1)
    {
        int tmpVal = str[idx] - '0';
        if (tmpVal < 1 || tmpVal > 9)
            return 0;
    }
    else
    {
        int tmpVal = (str[idx] - '0') + ((str[idx - 1] - '0') * 10);
        if (tmpVal < 1 || tmpVal > 26)
            return 0;
    }

    return (solution(str, size, idx + 1, 1) + solution(str, size, idx + 2, 2)) % 1000000;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie();
    int N;
    cin >> N;

    string str = to_string(N); // 문자열 전처리
    int size = str.size() - 1;

    if (size <= 0)
        cout << 0 << endl;
    else
        cout << (solution(str, size, 0, 1) + solution(str, size, 1, 2)) % 1000000 << endl;

    return 0;
}