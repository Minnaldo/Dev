#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

/**
 *  * Adjacency List BFS & DFS
 */

#define NODE 10 //노드의 수는 10이라 가정

using namespace std;

vector<int> BFS, DFS;               // BFS, DFS결과를 저장할 벡터
vector<vector<int>> adj_list(NODE); // 인접 리스트 저장 배열
vector<pair<int, int>> node_data;   // 간선 데이터가 저장될 배열
bool visit[NODE];                   // 방문 확인 배열

void Adjacency_List_BFS(int start)
{
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int cur = q.front();
        BFS.push_back(cur);

        for (int nxt : adj_list[cur]) // 현재 노드와 연결된 모든 노드를 탐색하며, 방문하지 않았으면 큐에 저장
        {
            if (!visit[nxt])
            {
                q.push(nxt);
                visit[nxt] = true;
            }
        }

        q.pop(); // 방문이 완료된 노드는 큐에서 삭제
    }
}

// used recursive function
void Adjacency_List_DFS(int cur)
{
    if (visit[cur]) // 현재 노드를 방문했으면 종료
        return;

    visit[cur] = true;
    DFS.push_back(cur); // 방문하지 않았으면 방문표시 후 저장

    for (int nxt : adj_list[cur])
    {
        if (!visit[nxt])
        {
            Adjacency_List_DFS(nxt);
        }
    }
}

// use stack
// void Adjacency_List_DFS_s(int start)
// {
//     stack<int> s;
//     s.push(start);

//     while (!s.empty())
//     {
//         int cur = s.top();
//         for (int nxt : adj_list[cur])
//         {
//             if (!visit[nxt])
//             {
//                 s.push(nxt);
//                 visit[nxt] = true;
//                 break;
//             }
//             else
//             {
//                 s.pop();
//                 break;
//             }
//         }
//     }
// }

void make_adjacency_list()
{
    int size = node_data.size();

    for (int i = 0; i < size; i++)
    {
        adj_list[node_data[i].first].push_back(node_data[i].second);
    }
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    int n; // 간선 데이터의 갯수를 저장할 변수
    scanf("%d", &n);
    while (n--)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        node_data.push_back(make_pair(start, end));
    }

    make_adjacency_list();

    Adjacency_List_BFS(1);
    memset(visit, false, sizeof(visit)); // 방문 배열 초기화

    Adjacency_List_DFS(1);

    // 내용 출력
    for (int i : BFS)
        cout << i << " ";
    cout << endl;
    for (int i : DFS)
        cout << i << " ";
    cout << endl;

    return 0;
}