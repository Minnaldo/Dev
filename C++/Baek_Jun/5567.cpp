#include <iostream>

/**
 *  * DFS 문제
 *  TODO
 */

using namespace std;

bool chk[500];
int dp[10001][2];
int n, m, ans;

void dfs(int v, int cnt)
{
    if (cnt == 2)
    {
        return;
    }

    for (int i = 1; i <= m; i++)
    {
        if (dp[i][0] == v && !chk[dp[i][1]])
        {
            ans++;
            chk[dp[i][1]] = true;
            dfs(dp[i][1], cnt++);
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &dp[i][0], &dp[i][1]);
    }

    for (int i = 1; i <= m; i++)
    {
        if (dp[i][0] == 1 && !chk[dp[i][1]])
        {
            chk[dp[i][1]] = true;
            dfs(dp[i][1], 1);
        }
    }

    printf("%d\n", ans);
    return 0;
}