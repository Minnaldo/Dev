#include <iostream>

/** 만취한 상범 백준_6359 ( https://www.acmicpc.net/problem/6359 )
 *  ? 완전탐색으로도 통과가 된다.
 *  * 완전탐색이 아닌 다른방법으로 통과하는 방법이 있을듯
 *  * another solution ==> (1~N 사이의 자연수 중 약수가 홀수인 수의 갯수)
 */

using namespace std;

int dp[101];

int solution(int n)
{
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j * i <= n; j++)
        {
            if (dp[j*i] == 1)
            {
                dp[j*i] = 0;
            }
            else
            {
                dp[j*i] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == 1)
            answer++;
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        cout << solution(k) << endl;
    }
    return 0;
}