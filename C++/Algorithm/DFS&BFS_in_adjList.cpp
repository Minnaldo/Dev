#include <iostream>
#include <queue>
#include <stack>
#include <vector>

/**
 *  * 참고 : https://mygumi.tistory.com/102
 */

using namespace std;

vector<vector<int>> adj_list;
vector<pair<int, int>> input_data;
vector<bool> visit;
int n; // 데이터 갯수

void init(int size)
{
    visit.assign(size, false);
    adj_list.assign(size, vector<int>());

    for (int i = 0; i < input_data.size(); i++)
    {
        int idx = input_data[i].first;
        int input = input_data[i].second;
        adj_list[idx].push_back(input);
    }
}

void BFS_in_adj_list(int start)
{
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        printf("%d ", cur);

        for (int nxt : adj_list[cur])
        {
            if (!visit[nxt])
            {
                visit[nxt] = true;
                q.push(nxt);
            }
        }
    }
}

// dfs in adj_list that use stack
void DFS_in_adj_list(int start)
{
    stack<int> s;
    s.push(start);
    printf("%d ", start);
    visit[start] = true;
    bool flag;

    while (!s.empty())
    {
        int cur = s.top();

        flag = false;

        for (int nxt : adj_list[cur])
        {
            if (!visit[nxt])
            {
                printf("%d ", nxt);
                visit[nxt] = true;
                flag = true;
                s.push(nxt);
                break;
            }
        }

        // back tracking
        if (!flag)
            s.pop();
    }
}

void DFS_in_adj_list_recur(int cur)
{
    printf("%d ", cur);
    visit[cur] = true;

    for (int nxt : adj_list[cur])
    {
        if (!visit[nxt])
        {
            DFS_in_adj_list_recur(nxt);
        }
    }
}

int main()
{
    freopen("bfs_dfs_input.txt", "r", stdin);

    cin >> n;
    n += 1;

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int first, second;
        scanf("%d %d", &first, &second);
        input_data.push_back(make_pair(first, second));
    }
    init(n);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << "\t";
    //     for (int j = 0; j < adj_list[i].size(); j++)
    //     {
    //         cout << adj_list[i].front() << " ";
    //         adj_list[i].pop();
    //     }
    //     cout << endl;
    // }

    printf("DFS in adj_list\n");
    DFS_in_adj_list(1);
    printf("\nEnd of DFS\n");
    printf("\n");
    fill_n(visit.begin(), n, false);
    printf("DFS in adj_list ver. Recur\n");
    DFS_in_adj_list_recur(1);
    printf("\nEnd of DFS\n");
    // fill_n(visit.begin(), n, false);
    // printf("BFS in adj_list\n");
    // BFS_in_adj_list(1);
    // printf("\nEnd of BFS\n");

    return 0;
}