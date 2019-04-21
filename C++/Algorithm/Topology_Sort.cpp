#include <iostream>
#include <queue>
#include <vector>

/**
 *  * 진입차수가 0인 노드를 큐에 넣는다.
 *  * 큐의 제일 앞 원소를 가져와 다시 위의 연산 수행
 *  * 큐가 빌 때까지 반복
 */

#define intP pair<int, int>

using namespace std;

int n;
vector<int> degree; // 노드의 개수를 1000개로 가정
vector<intP> sequence;
vector<bool> visit(10000);
vector<int> answer;

// BFS와 유사한 방식의 위상정렬
void topology_sort()
{
    degree.assign(n, 0);
    for (int i = 0; i < n; i++)
        degree[sequence[i].second]++;

    queue<int> q;

    // initialize
    for (int i = 0; i < degree.size(); i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
            visit[i] = true;
        }
    }

    while (!q.empty())
    {
        int curNode = q.front();
        answer.push_back(curNode);

        for (int i = 0; i < n; i++)
        {
            if (!visit[sequence[i].second] && sequence[i].first == curNode)
            {
                q.push(sequence[i].second);
                visit[sequence[i].second] = true;
                if (degree[sequence[i].second] > 0)
                    degree[sequence[i].second] -= 1;
            }
        }

        q.pop();
    }
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    // cin >> n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int tmp, tmp2;
        // cin >> tmp >> tmp2;
        scanf("%d %d", &tmp, &tmp2);
        sequence.push_back(make_pair(tmp, tmp2));
    }

    topology_sort();

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}