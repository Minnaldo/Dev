#include <algorithm>
#include <cstring> // NOTE purpose to use the memset function
#include <iostream>
#include <queue>
#include <vector>

/** DFS와 BFS 백준_1260 ( https://www.acmicpc.net/problem/1260 )
 *  NOTE  how to used the BFS and DFS algorithm in adjacency list
 */

using namespace std;

bool chk[1001];
vector<vector<int>> arr(1001);

// the DFS search that use recursive
void dfs(int current)
{
    chk[current] = true;
    printf("%d ", current);

    int size = arr[current].size();
    for (int i = 0; i < size; i++)
    {
        if (!chk[arr[current][i]])
        {
            dfs(arr[current][i]);
        }
    }
}

void bfs(int start)
{
    memset(chk, false, sizeof(chk)); //NOTE this function is in the cstring header
    int current;
    queue<int> q;
    q.push(start);
    chk[start] = true;

    while (!q.empty())
    {
        current = q.front();
        printf("%d ", current);
        int size = arr[current].size();
        for (int i = 0; i < size; i++)
        {
            if (!chk[arr[current][i]])
            {
                chk[arr[current][i]] = true;
                q.push(arr[current][i]);
            }
        }
        q.pop();
    }
}

int main(int argc, char const *argv[])
{
    int N, M, start;
    scanf("%d %d %d", &N, &M, &start);

    int y, x;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &y, &x);
        // NOTE make the adjancecy list, why do this that double push
        // * y에 대한 데이터 x에 대한 데이터 두개를 넣는 이유 --> 무방향 그래프 이기 때문
        arr[y].push_back(x);
        arr[x].push_back(y);
    }

    for (int i = 1; i <= N; i++)
        sort(arr[i].begin(), arr[i].end());

    dfs(start);
    printf("\n");
    bfs(start);
    printf("\n");
    return 0;
}