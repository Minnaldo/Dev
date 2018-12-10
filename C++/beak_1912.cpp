#include <iostream>
#include <sstream>

using namespace std;

/** 연속합 백준_1912 (https://www.acmicpc.net/problem/1912)
 *  * 음수를 더하여도 최대가 될 수있는 경우가 생김
 *  * 점화식 dp[n] = n에서 나올 수 있는 연속합 중 최댓값
 *  ! dp[n-1] + arr[n] < 0 && dp[n-1] < 0 일 때, arr[n]을 더하는 것은 의미가 없다 ==> dp[m] = arr[n]
 *  ! 이 외의 경우 기본적인 점화식은 dp[n] = dp[n-1] + arr[n]이 성립한다
 */

int dp[100001];

int max(int a, int b)
{
    return a > b ? a : b;
}
int solution(int n, int *arr)
{
    int ans = dp[1];
    for (int i = 2; i <= n; i++)
    {
        if (dp[i - 1] + arr[i] > 0 && dp[i - 1] > 0)
        {
            dp[i] = dp[i - 1] + arr[i];
        }
        else
        {
            dp[i] = arr[i];
        }

        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string str = "10 10 -4 3 1 5 6 -35 12 21 -1"; //33
    string str2 = "5 -1 0 5 -3 4";                // 5
    stringstream ss;
    ss.str(str);

    int T;
    ss >> T;

    int *arr = new int[T + 1];
    for (int i = 1; i <= T; i++)
    {
        int tmp;
        ss >> tmp;
        arr[i] = tmp;
    }
    dp[1] = arr[1];
    cout << solution(T, arr) << endl;
    return 0;
}