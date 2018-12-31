#include <iostream>

/** atCoder Remainder Reminder (https://atcoder.jp/contests/arc091/tasks/arc091_b)
 *  * 속도가 살짝 아쉬움, 더욱 빠르게 가능할 듯
 *  * 계산하는 범위를 줄임으로써 계산속도를 늘림
 */

using namespace std;

long long solution(long long n, long long k)
{
    long long ans = 0;
    for (int i = k + 1; i <= n; i++) //  b의 범위 제한
    {
        for (int j = 1; j <= n; j++) //  a의 범위
        {
            if (j % i >= k)
            {
                ans++;
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    long long n, k;

    cin >> n >> k;

    cout << solution(n, k) << endl;
    return 0;
}