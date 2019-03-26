#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

/** DFS와 BFS 백준_1260 ( https://www.acmicpc.net/problem/1260 )
 *
 */

using namespace std;

bool chk[1001];
vector<vector<int>> arr(1001);

void dfs(int current)
{
    chk[current] = true;

    printf("%d ", current);
    for (int i = 0; i < arr[current].size(); i++)
    {
        if (!chk[arr[current][i]])
        {
            dfs(arr[current][i]);
        }
    }
}

void bfs(int start)
{
    memset(chk, false, sizeof(chk));
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
    fstream fs("input.txt");
    int N, M, start;
    // scanf("%d %d %d", &N, &M, &start);
    fs >> N >> M >> start;

    int y, x;
    for (int i = 0; i < M; i++)
    {
        // scanf("%d %d", &y, &x);
        fs >> y >> x;
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