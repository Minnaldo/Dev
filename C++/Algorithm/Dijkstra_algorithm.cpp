#include <iostream>

/** Dijkstra Algorithm (다익스트라 알고리즘)
 *
 */

using namespace std;

bool visit[10];
int graph[10][10]; // graph[i][j] == i->j 의 가중치 (역은 성립하지 않는다), 0일 경우 무 방향 (길 없음)
int arr[10];       // 경로 가중치를 저장할 배열

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

    printf("%d\n", arr[end - 1]); // 0부터 시작하므로 -1 해준다

    return 0;
}