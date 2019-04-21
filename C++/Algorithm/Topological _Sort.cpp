#include <iostream>
#include <queue>
#include <vector>

/** Topological_sorting 위상 정렬
 *  유향 그래프의 꼭짓점들을 변의 방향을 거스르지 않도록 나열하는 방법
 *  ! 선행조건 : 유향그래프여야 함, 순환하지 않아야 함
 *  * 진입차수가 0인 노드를 큐에 넣는다.
 *  * 큐의 제일 앞 원소를 가져와 다시 위의 연산 수행
 *  * 큐가 빌 때까지 반복
 */

using namespace std;

int n;
vector<int> degree(10); // 노드의 개수를 1000개로 가정
vector<vector<int>> graph(10);
vector<int> answer; // 위상정렬의 결과를 저장할 벡터

// BFS와 유사한 방식의 위상정렬
void topology_sort()
{
    queue<int> q;

    // initialize : 선행 정점을 갖지 않는 정점을 큐에 삽입
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 0) // 정점의 차수가 0일 때
            q.push(i);
    }

    // 정점의 수만큼 반복한다.
    for (int i = 0; i < n; i++)
    {
        int v = q.front();
        answer.push_back(v); // 차수가 0일때 큐에 들어가므로, q에 들어간 순서대로 답이 된다.

        // 정점과 연결된 모든 정점에 대해 수행
        for (int nxtV : graph[v])
        {
            degree[nxtV]--; // 차수값을 감소

            if (degree[nxtV] == 0) // 차수가 0인 정점 ( 선행 정점을 갖지 않는 정점 )을 큐에 삽입
                q.push(nxtV);
        }
        q.pop();
    }
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int tmp, tmp2;
        scanf("%d %d", &tmp, &tmp2);
        graph[tmp].push_back(tmp2); // 인접리스트 이용
        degree[tmp2]++;             // 삽입과 함께 정점의 차수 증가
    }

    topology_sort();

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}