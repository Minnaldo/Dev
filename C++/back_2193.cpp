#include <iostream>

/** 이친수 - 백준_2193 (https://www.acmicpc.net/problem/2193)
 *  * 방사형태로 퍼져나가며 결정하는 문제 ( <=> 한가지 결과로 수렴해가는 문제 )
 *  * dp[n] = dp[n-1] + dp[n-2] ==> 길이가 n인 이친수의 갯수는 n-2번째 이친수의 갯수 + n-1번째 이친수의 갯수
 *  * n자릿수의 이친수 중 끝자리가 1인 이친수의 갯수 = n-1자릿수의 이친수중 끝자리가 0인 이친수 갯수
 *  * n자릿수의 이친수 중 끝자리가 0인 이친수의 갯수 = n-1자릿수의 이친수중 끝자리가 0인 이친수의 갯수 + 1인 이친수의 갯수
 *  참조 : (https://m.blog.naver.com/PostView.nhn?blogId=occidere&logNo=220788046159&proxyReferer=https%3A%2F%2Fwww.google.com%2F)
 *  참조 : (http://baked-corn.tistory.com/79)
 */

using namespace std;

long long dp[90];

long long solution(int n)
{
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    cout << solution(N) << endl;
    return 0;
}