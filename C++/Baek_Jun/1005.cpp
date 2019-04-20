#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

/** ACM Craft 백준_1005
 *  * 목표 건물부터 내려오자, BFS?
 *  ! 예외 조건!
 */

using namespace std;

int T, n, k, w, ans, lastLv;
vector<int> build(1001);
vector<vector<int>> sequence(100000, vector<int>(2));
bool visit[1001];
vector<int> levelChk(10001);

int max(int &a, int &b) { return a > b ? a : b; }

void solution(int start)
{
    queue<pair<int, int>> q;
    int level = 1;
    q.push(make_pair(start, level));
    levelChk[level] = build[start];
    visit[start] = true;

    while (!q.empty())
    {
        int tmp = -1;
        int cur = q.front().first;
        int curLv = q.front().second;

        for (int i = 0; i < k; i++)
            if (!visit[sequence[i][0]] && sequence[i][1] == cur)
            {
                int nxtBuild = sequence[i][0];
                q.push(make_pair(sequence[i][0], curLv + 1));
                visit[sequence[i][0]] = true;
                tmp = tmp > build[nxtBuild] ? tmp : build[nxtBuild];
            }

        levelChk[curLv + 1] = max(levelChk[curLv + 1], tmp);
        lastLv = lastLv < curLv + 1 ? curLv + 1 : lastLv;
        q.pop();
    }
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        scanf("%d %d", &n, &k); // 건물 번호 1~N

        for (int i = 1; i <= n; i++)
            scanf("%d", &build[i]);

        for (int i = 0; i < k; i++)
            for (int j = 0; j < 2; j++)
                scanf("%d", &sequence[i][j]);

        scanf("%d", &w);

        solution(w); // 1번 건물부터 시작

        for (int i = 0; i < lastLv; i++)
            ans += levelChk[i];

        printf("%d\n", ans);

        memset(visit, false, sizeof(visit));
        fill_n(levelChk.begin(), levelChk.size(), 0);
    }

    return 0;
}