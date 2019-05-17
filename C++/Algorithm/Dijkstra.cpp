#include <iostream>
#include <vector>

/** Dijkstra Algorithm (다익스트라 알고리즘)
 *  * 그래프에서 최단경로를 찾기, 다이나믹 프로그래밍의 응용
 *  * 시간복잡도 O(N^2) --> 힙구조를 사용하여 O(N * log N)으로 개선 가능
 *  * ref : https://blog.naver.com/PostView.nhn?blogId=ndb796&logNo=221234424646&parentCategoryNo=&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView
 *  TODO write the dijstra algorithme code that use heap structure
 */

using namespace std;

#define INF 987654321

int vertex, edge;
vector<vector<int>> adj_mat;
vector<int> dst;
vector<bool> visit;

int min(int &a, int &b) { return a < b ? a : b; }

// 방문하지 않은 노드중 가장 작은 값을 가지는 노드의 인덱스를 반환한다
int getSmallIdx()
{
    int min = INF;
    int idx = 0;

    for (int i = 1; i <= vertex; i++)
    {
        if (dst[i] < min && !visit[i])
        {
            min = dst[i];
            idx = i;
        }
    }
    return idx;
}

void update(int start)
{
    // 초기 설정
    for (int i = 1; i <= vertex; i++)
        dst[i] = adj_mat[start][i];
    visit[start] = true;

    // 노드 갯수만큼 연산하지 않고, 노드갯수 -2 만큼 반복하는 이유 -->
    // 첫번째 노드에서 출발과, 마지막 노드로의 도착은 계산하지 않아도 된다. ==> 경로 가중치가 변하지 않는다.
    int loop = vertex - 2;
    while (loop--)
    {
        int current = getSmallIdx();
        visit[current] = true;
        for (int i = 1; i <= vertex; i++)
        {
            if (!visit[i])
            {
                // 저장되어 있는 i까지 오는 비용 vs current를 들려서 i까지 오는 비용
                dst[i] = min(dst[i], dst[current] + adj_mat[current][i]);
            }
        }
    }
}

void dijkstra(int start)
{
    visit[start] = true; // 시작점 방문 표시
    for (int i = 1; i <= vertex; i++)
    {
        if (start == i)
            dst[i] = 0;
        else
            dst[i] = min(dst[i], adj_mat[start][i]);
    }
}

int main(int argc, char const *argv[])
{
    freopen("dijkstra.txt", "r", stdin);

    scanf("%d %d", &vertex, &edge);

    adj_mat.assign(vertex + 1, vector<int>(vertex + 1, INF));
    dst.assign(vertex + 1, INF);
    visit.assign(vertex + 1, false);

    for (int i = 1; i <= edge; i++)
    {
        int src, dest, val;
        scanf("%d %d %d", &src, &dest, &val);

        adj_mat[src][dest] = val;
    }

    cout << "before dijkstra" << endl;
    for (int i = 1; i <= vertex; i++)
        cout << dst[i] << " ";
    cout << endl
         << endl;

    dijkstra(1);

    cout << "after dijkstra" << endl;
    for (int i = 1; i <= vertex; i++)
        cout << dst[i] << " ";
    cout << endl;

    return 0;
}