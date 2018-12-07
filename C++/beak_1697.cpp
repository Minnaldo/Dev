#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dp[100001];

int solution(int n, int k)
{
    queue<int> q;
    q.push(n);
    dp[n] = 1;
    dp[k] = 987654321;
    while (!q.empty())
    {
        int cur_pos = q.front();

        for (int i = 0; i < 3; i++)
        {
            int nxt_pos = 0;
            if (i == 0)
            {
                nxt_pos = cur_pos + 1;
            }
            else if (i == 1)
            {
                nxt_pos = cur_pos - 1;
            }
            else if (i == 2)
            {
                nxt_pos = cur_pos * 2;
            }

            if (nxt_pos >= 0 && nxt_pos <= 100000)
            {
                q.push(nxt_pos);
                dp[nxt_pos] = min(dp[cur_pos] + 1, dp[nxt_pos]);
            }
        }
        q.pop();

        if (q.front() == k)
        {
        }
    }
}

int main(int argc, char const *argv[])
{
    int S = 5, B = 17; // 4
    // cin >> S >> B;

    cout << solution(S, B) << endl;

    return 0;
}