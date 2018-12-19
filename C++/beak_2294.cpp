#include <fstream>
#include <iostream>

/** 동전2 백준_2294 (https://www.acmicpc.net/problem/2294)
 *  * dp[n] = n을 나타내는데 사용한 동전의 최소 갯수
 *  * 참조 (https://blog.naver.com/occidere/220794872664)
 *  * 초기값 = 10001, 초기값에서 변하지 않았다면 이는 방법의 가짓수가 매우 크다는 뜻이므로, 이 때에 -1을 리턴한다
 *  * 비교 순서 --> arr[1]로 만들수 있는 경우의수, arr[2]로, arr[3], ... , arr[n]을 비교한다.
 */

using namespace std;

int dp[10001];

int min(int a, int b)
{
    return a < b ? a : b;
}

int solution(int n, int k, int *arr)
{
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= k; i++)
        {
            if (i >= arr[j])
            {
                dp[i] = min(dp[i], dp[i - arr[j]] + 1); // dp[i - arr[j]] +1 의 이유 ==> dp[i] 는 i를 만들 수 있는 동전의 최소 갯수, arr은 동전의 가치
                                                        // i 가 5일때 dp[i]를 나타내려면 dp[0]에서 5원가치를 더할경우 dp[5]가 됨, 그러므로 dp[i-arr[j]] + 1이 성립
            }
        }
    }

    if (dp[k] == 10001)
    {
        return (-1);
    }

    return dp[k];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int n, K, tmp;

    fstream fs("input.txt");

    fs >> n >> K;
    int *arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        fs >> tmp;
        arr[i] = tmp;
    }
    //pre-processing   --> 초기값 설정 = 설정값이 가장 클 경우의 수는 동전 가치의 최솟값 + 동전 개수의 최대값 ==> 10001로 초기화
    for (int i = 1; i <= K; i++)
    {
        dp[i] = 10001;
    }
    dp[0] = 0; // 제대로된 비교를 진행하기 위해 ex) dp[1] = 10001, d[i - arr[j]] + 1 = 1 이므로
    cout << solution(n, K, arr) << "\n";
    return 0;
}