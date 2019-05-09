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

// make adj_matrix
void init(int size)
{
    visit.assign(size + 1, false);
    adj_matrix.assign(size + 1, vector<int>(size + 1, 0));

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

        for (int i = 0; i <= n; i++)
        {
            int nxt = adj_matrix[cur][i];
            if (!visit[nxt] && nxt == 1)
            {
                q.push(nxt);
                visit[nxt] = true;
            }
        }
        q.pop();
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
    freopen("bfs_dfs_input.txt", "r", stdin);
    scanf("%d", &n);
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int first, second;
        scanf("%d %d", &first, &second);
        input_data.push_back(make_pair(first, second));
    }

    init(n);

    for (int i = 0; i < n; i++)
    {
        for (int nxt : adj_matrix[i])
            cout << nxt << " ";
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
            cout << "false ";
        else
            cout << "true ";
    }
    cout << endl;

    bfs(1);
    cout << endl;

    return 0;
}