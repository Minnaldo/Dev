#include <iostream>
#include <queue>

using namespace std;

/** 숨바꼭질 백준_1697 (https://www.acmicpc.net/problem/1697)
 *  ! 메모리초과
 *  REVIEW
 */

int dp[100000], cnt;

int min(int a, int b)
{
    return a < b ? a : b;
}

int solution(int n, int k)
{
    queue<int> q;
    q.push(n);
    dp[n] = 0;

    while (!q.empty())
    {
        int cur_pos = q.front();

        while (cnt < 3)
        {
            int nxt_pos;

            switch (cnt)
            {
            case 0:
                nxt_pos = cur_pos + 1;
                break;
            case 1:
                nxt_pos = cur_pos - 1;
                break;
            case 2:
                nxt_pos = cur_pos * 2;
                break;
            }

            if (nxt_pos >= 0 && nxt_pos <= 100000)
            {
                q.push(nxt_pos);
                dp[nxt_pos] = min(dp[cur_pos] + 1, dp[nxt_pos]);
            }
            cnt++;
        }
        cnt = 0;

        q.pop();

        if (q.front() == k)
        {
            break;
        }
    }
    return dp[k];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    // int S = 5, B = 17; // 4
    int S = 4, B = 100000;  //seg fault
    // int S, B;
    // cin >> S >> B;

    //초기값 100001의 이유 --> 아무리 오래걸려도 이시간 이내에는 도착할 것이다. == 이보다 큰 값은 나올 리 없다
    for (int i = 0; i < 100000; i++)
    {
        dp[i] = 100001;
    }

    cout << solution(S, B) << endl;

    return 0;
}