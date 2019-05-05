#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

/**
 *
 */

using namespace std;

int n;
vector<vector<int>> adj_matrix;
vector<pair<int, int>> input_data;
vector<bool> visit;

void init(int size)
{
    visit.assign(size, false);
    adj_matrix.assign(size, vector<int>(size));

    for (int i = 0; i < input_data.size(); i++)
    {
        int idx = input_data[i].first;
        int input = input_data[i].second;
        adj_matrix[idx][input] = adj_matrix[input][idx] = 1;
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        printf("%d ", cur);
        q.pop();

        for (int nxt : adj_matrix[cur])
        {
            if (!visit[nxt] && nxt != cur)
            {
                q.push(nxt);
                visit[nxt] = true;
            }
        }
    }
}

void dfs(int cur)
{
    visit[cur] = true;
    printf("%d ", cur);

    for (int nxt : adj_matrix[cur])
    {
        if (!visit[nxt])
        {
            dfs(nxt);
        }
    }
}

void dfs_stack(int cur)
{
    stack<int> s;
    s.push(cur);
    visit[cur] = true;
    bool flag = false;

    while (!s.empty())
    {
        for (int nxt : adj_matrix[cur])
        {
            if (!visit[nxt])
            {
                printf("%d ", nxt);
                s.push(nxt);
                flag = true;
                visit[nxt] = true;
                break;
            }
        }

        // back tracking
        if (!flag)
            s.pop();
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}