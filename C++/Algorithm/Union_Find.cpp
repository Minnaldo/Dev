#include <iostream>

/** Union_Find (합집합 찾기)
 *  * index = 자기 자신 노드 , arr[index] = 부모 노드
 *  * 합집합인지 확인하는 알고리즘
 */

using namespace std;

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
    int arr[11];

    // UnionFind 테이블 초기화
    for (int i = 1; i <= 10; i++)
        arr[i] = i;

    unionParent(arr, 1, 2);
    unionParent(arr, 2, 3);
    unionParent(arr, 3, 4);
    unionParent(arr, 5, 6);
    unionParent(arr, 6, 7);
    unionParent(arr, 7, 8);
    unionParent(arr, 9, 10);

    if (findParent(arr, 9, 10))
        cout << "Uninon" << endl;
    else
        cout << "Not Union" << endl;

    unionParent(arr, 1, 9);
    if (findParent(arr, 1, 10))
        cout << "Uninon" << endl;
    else
        cout << "Not Union" << endl;

    return 0;
}