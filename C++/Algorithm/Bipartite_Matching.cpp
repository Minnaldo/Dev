#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

/** Bipartite Matching 이분 매칭
 *
 */

using namespace std;

int n, m; // n : A그룹 크기, m : B그룹 크기
bool visit[100];
int b[100];               // index와 연결된 노드의 번호를 저장, b[1] = 5 일 경우, 1번 노드와 5번 노드가 연결되어 있는 상태임
vector<vector<int>> node; // 인접 리스트 형태로 연결 표시

int dfs(int here)
{
    if (visit[here])
        return 0;       // 방문된 점은 매칭 안됨
    visit[here] = true; // 매칭 표시

    // 현재 노드와 연결되어있는 상대 노드들의 갯수만큼 반복하며 판단
    for (int i = 0; i < node[here].size(); i++)
    {
        int there = node[here][i];

        // 현재 노드와 매칭이 되지않은 노드이거나 || 이미 매칭된 노드가 다른 노드와 매칭이 가능할 때
        if (!b[there] || dfs(b[there]))
        {
            b[there] = here;
            return 1;
        }
    }
    return 0;
}

int bMatch()
{
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        memset(visit, false, sizeof(visit));
        if (dfs(i))
            ret++;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < 10; i++)
    {
        int tmp, tmp2;
        scanf("%d %d", &tmp, &tmp2);

        node[tmp].push_back(tmp2); // 인접 리스트 생성
    }

    int ans = bMatch();
    printf("%d\n", ans);
    return 0;
}