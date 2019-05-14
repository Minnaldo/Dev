#include <iostream>
#include <vector>

using namespace std;

#define INF INT32_MAX

vector<vector<int>> adj_matrix;
vector<int> dst, visit;
int vertex;

void djikstra(int start, int end)
{
    int min, v;

    for (int i = 0; i < vertex; i++)
    {
        min = INF;
        for (int j = 0; j < vertex; j++)
        {
            // 현재 노드에서 방문하지 않은 노드중 가중치가 가장 적은 노드를 찾는다
            if (!visit[j] && min > dst[j])
            {
                min = dst[j];
                v = j;
            }
        }

        // 방문 표시
        visit[v] = true;

        for (int j = 0; j < vertex; j++)
        {
            // 가중치 값 업데이트
            // 다음 노드까지 가는 가중치 최솟값이, 현재 노드까지 오는 가중치 최솟값 + 현재 노드에서 다음 노드로 가는 가중치값보다 크면, 갱신한다
            if (dst[j] > dst[v] + adj_matrix[v][j])
            {
                dst[j] = dst[v] + adj_matrix[v][j];
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    int n, start, end;
    cin >> vertex;

    cin >> start >> end;

    adj_matrix.assign(n, vector<int>(n, 0));

    // make adj_matrix
    for (int i = 0; i < n; i++)
    {
        adj_matrix[i][i] = 0;
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        adj_matrix[tmp1][tmp2] = tmp3;
    }

    // 현재까지의 거리를 저장할 배열
    dst.assign(n, INF);
    // 방문 여부를 저장할 배열
    visit.assign(n, false);

    djikstra(start, end);

    return 0;
}