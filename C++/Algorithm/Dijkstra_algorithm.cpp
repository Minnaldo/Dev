#include <iostream>
#include <queue>
#include <vector>

/** Dijkstra Algorithm (다익스트라 알고리즘)
 *
 */

using namespace std;

bool visit[10];
int arr[10]; // 경로 가중치를 저장할 배열

int graph[10][10];                             // O(N^2) 방식의 dijkstra 알고리즘
vector<vector<pair<int, int>>> graph_heap(10); // heap 이용 O(N log N) Dijkstra 알고리즘

// O( N^2 ) 시간 복잡도를 갖는다.
void dijikstra(int start)
{
    int number = 10; // 노드의 개수
    fill(arr, arr + number, INT32_MAX);
    for (int i = 0; i < number; i++) // number == 노드의 개수
    {
        arr[i] = graph[start][i]; // 출발지점에서의 가중치로 초기화 해준다, 경로가 없으면 무한대
    }

    visit[start] = true; // 방문 체크

    for (int i = 0; i < number - 2; i++)    // 왜 number - 2 를 할까?
    {
        int current;
        // 최소거리를 찾는다.
        int min = INT32_MAX;
        for(int j =0; j<number; j++)
        {
            if(arr[j] < min && !visit[j])
            {
                min = arr[i];
                current = i;
            }
        }

        visit[current] = true;

        for (int j = 0; j < 6; j++)
        {
            if (!visit[j])
                if (arr[current] + graph[current][j] < arr[j])
                    arr[j] = arr[current] + graph[current][j];
        }
    }
}

// heap 구조 다익스트라 알고리즘, O( N log N ) 시간을 갖는다.
void dijikstra_heap(int start)
{
    arr[start] = 0;
    priority_queue<pair<int, int>> pq; // pq[1].first = 2 이면, 1번 노드에서 2번노드로 가는길, 가중치 = pq[1].second
    pq.push(make_pair(start, 0));

    while (!pq.empty())
    {
        int current = pq.top().first;   // 가장 상단에 있는 근접 노드 번호
        int distance = pq.top().second; // 짧은 것이 먼저 오도록 음수화 한다. ???
        pq.pop();

        if (arr[current] < distance)
            continue; // 최단거리가 아닐 경우 건너 뛴다.

        for (int i = 0; i < graph_heap[current].size(); i++)
        {
            int next = graph_heap[current][i].first;                 // 현재 노드의 인접 노드 ( 갈 수 있는 노드 )
            int nextDist = distance + graph_heap[current][i].second; // 인접 노드로 진행할 경우의 가중치

            if (nextDist < arr[next])
            {
                arr[next] = nextDist;
                pq.push(make_pair(next, nextDist));
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int start = 0, end = 0;
    scanf("%d %d", &start, &end);
    int current = start;
    int tmp = INT32_MAX;
    // fill(arr, arr + 10, -1); // -1로 초기화 한다.
    for (int i = current + 1; i < 10; i++)
    {
        if (graph[current][i] != 0)
        {
            tmp = tmp < graph[current][i] ? tmp : graph[current][i];
        }
        arr[i] = (arr[i] == -1 ? tmp : (arr[i] + tmp));
        visit[current] = true;
    }

    graph_heap[1].push_back(make_pair(2, 2));

    printf("%d\n", arr[end - 1]); // 0부터 시작하므로 -1 해준다

    return 0;
}