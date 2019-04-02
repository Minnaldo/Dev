#include <algorithm>
#include <iostream>
#include <vector>

/** Kruskal Algorithm
 *  * 최소 스패닝 트리를 찾는 알고리즘
 *  * UnionFind를 이용하여 Cycle이 생기지 않게 한다
 *  @Param - sum : 최소 비용을 출력한다.
 */

using namespace std;

struct node
{
  public:
    int cost;  // 간선 비용
    int start; // 간선 시작점
    int end;   // 간선 끝점

    node(int a, int b, int c)
    {
        start = a;
        end = b;
        cost = c;
    }
};

// 재귀함수를 통해 원소값 갱신
int getParent(int *arr, int x)
{
    if (arr[x] == x)
        return x;

    return arr[x] = getParent(arr, arr[x]);
}

// a노드와 b노드를 합집합
int unionParent(int *arr, int a, int b)
{
    a = getParent(arr, a);
    b = getParent(arr, b);

    // 합쳐진 노드 중, 원소가 작은 노드의 값으로 갱신
    if (a < b)
        arr[b] = a;
    else
        arr[a] = b;
}
bool findParent(int *arr, int a, int b)
{
    a = getParent(arr, a);
    b = getParent(arr, b);
    if (a == b)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    int arr[7];
    for (int i = 0; i < 7; i++)
        arr[i] = i;

    vector<node> kru;

    kru.push_back(node(1, 7, 12));
    kru.push_back(node(1, 4, 28));
    kru.push_back(node(1, 2, 67));
    kru.push_back(node(1, 5, 17));
    kru.push_back(node(2, 4, 24));
    kru.push_back(node(2, 5, 62));
    kru.push_back(node(3, 5, 20));
    kru.push_back(node(3, 6, 37));
    kru.push_back(node(4, 7, 13));
    kru.push_back(node(5, 6, 45));
    kru.push_back(node(5, 7, 73));

    // 간선의 비용으로 오름차순 정렬
    sort(kru.begin(), kru.end(), [](node a, node b) {
        return a.cost < b.cost ? true : false;
    });

    int sum = 0; // 거리의 합 초기화

    for (int i = 0; i < kru.size(); i++)
    {
        // 사이클이 발생하지 않을 때 ( 동일한 부모를 가리키지 않을 때 )
        if (!findParent(arr, kru[i].start, kru[i].end))
        {
            sum += kru[i].cost;
            unionParent(arr, kru[i].start, kru[i].end);
        }
    }

    printf("%d\n", sum);

    return 0;
}