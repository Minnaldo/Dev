#include <iostream>
#include <vector>

/** Foyd-Warshall Alogrithm (플로이드 - 와샬 알고리즘)
 *  "거쳐가는 정점"을 기준으로 최단거리를 구한다!
 *  다이나믹 프로그래밍을 활용한 알고리즘이다
 *  특징) 음수가중치를 갖는 엣지에 대해서도 계산이 가능하다 ( 단, 음수 사이클이 없는 그래프여야 한다 ) <-> 다익스트라 알고리즘과 다른 부분
 *  특징 2) multiple Source multiple destination 에 대하여 최단 경로를 계산
 *  TODO how to get path that minimum weight value, not value
 */

using namespace std;

#define INF 987654321

int vertex, edge;
vector<vector<int>> adj_mat;

int min(int &a, int &b) { return a < b ? a : b; }

// 노드값을 받아, 받은 노드를 지나는 값을 계산한다.
void floyd()
{
    for (int k = 1; k <= vertex; k++)
    {
        for (int i = 1; i <= vertex; i++)
        {
            for (int j = 1; j <= vertex; j++)
            {
                // 현재 가지고 있는 경로 최솟값 vs k를 거쳐 오늘 경로의 최솟값
                adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    freopen("Floyd.txt", "r", stdin);

    scanf("%d %d", &vertex, &edge);

    // vertex X vertex 개의 원소를 가진 2차원 행렬 생성
    adj_mat.assign(vertex + 1, vector<int>(vertex + 1, INF));

    for (int i = 1; i <= vertex; i++)
        adj_mat[i][i] = 0;

    for (int i = 0; i < edge; i++)
    {
        int src, dest, val;
        scanf("%d %d %d", &src, &dest, &val);
        adj_mat[src][dest] = val;
    }

    cout << "before Floyd algo" << endl;
    for (int i = 1; i <= vertex; i++)
    {
        for (int j = 1; j <= vertex; j++)
            cout << adj_mat[i][j] << " ";
        cout << endl;
    }

    floyd();
    cout << endl
         << "after Floyd algo" << endl;
    for (int i = 1; i <= vertex; i++)
    {
        for (int j = 1; j <= vertex; j++)
            cout << adj_mat[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}