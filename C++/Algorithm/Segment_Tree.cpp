#include <iostream>
#include <math.h>

/** 세그먼트 트리 ( Segment Tree )
 *  * 자주 변화하는 배열의 구간합을 구하는데 유용하다
 *  * lazy propagation (게으른 전파) : 노드의 업데이트를 매번 리프노드까지 전부 수행하지 않고, 필요할 때에만 함으로써, 구간내의 자료를 모두 업데이트 하는 연산마저 logN시간에 끝낼 수 있게 한다.
 *  * lazy propagation : 새로운 배열을 생성하여, 업데이트 되는 값들을 저장해두고, sum, update 함수가 실행하기 전에 자식 노드들을 업데이트 한다.
 *  REVIEW
 */

using namespace std;

int *tree; // 세그먼트 트리를 저장할 배열
int *arr;  // 데이터가 들어오는 배열
int *lazy;

int init(int index, int left, int right)
{
    if (left == right)
        return tree[index] = arr[left];

    int mid = (left + right) / 2;
    return tree[index] = init(index * 2, left, mid) + init(index * 2 + 1, mid + 1, right);
}

int sum(int index, int start, int end, int left, int right)
{
    update_lazy(index, start, end);
    if (right > start || end < left)
        return 0;
    if (start >= left && right >= end)
        return tree[index];
    int mid = (start + end) / 2;
    return sum(index * 2, start, mid, left, right) + sum(index * 2 + 1, mid + 1, end, left, right);
}

// diff = 바꾸려는 값
// change_idx = 값을 바꾸려는 노드의 번호
// [start, end] = 현재 탐색하고있 노드의 범위, index = 현재 탐색하고 있는 노드의 인덱스
void update_range(int index, int start, int end, int left, int right, int diff)
{
    // 게으른 전파의 업데이트 함수
    update_lazy(index, start, end);
    if (end < left || right < start)    // 범위 바깥
        return;
    if (left <= start && end <= right)
    {
        tree[index] += (end - start + 1) * diff;
        if (start != end)
        {
            lazy[index * 2] += diff;
            lazy[index * 2 + 1] += diff;
        }
        return;
    }

    int mid = (start + end) / 2;
    update_range(index * 2, start, mid, left, right, diff);       // 왼쪽 자식 노드
    update_range(index * 2 + 1, mid + 1, end, left, right, diff); // 오른쪽 자식 노드
}

void update_lazy(int idx, int start, int end)
{
    if (lazy[idx] != 0)
    {
        // end-start+1 의 의미 : 일정 구간을 업데이트 할 때, 현재 노드가 리프노드가 아닌 경우, 내가 갖고있는 자식 노드의 수만큼 diff값이 증가한다 즉, diff * 자식 노드의 수가 되므로, 업데이트할 데이터 * 자식노드의 수를 곱하게 되는데, 아래 코드가 해당 코드가 된다.
        tree[idx] += (end - start + 1) * lazy[idx];
        if (start != end)
        {
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

// 일반 세그먼트 트리의 업데이트 함수
void update(int changed_idx, int diff, int idx, int start, int end)
{
    if (changed_idx < start || changed_idx > end)
        return;
    tree[idx] += diff;

    if (start != end)
    {
        int mid = (start + end) / 2;
        update(changed_idx, diff, idx * 2 + 1, start, mid);
        update(changed_idx, diff, idx * 2 + 1, mid + 1, end);
    }
}

// 트리의 높이 : 데이터의 갯수(N)가 2의 제곱꼴 ==> Full binary tree, 높이 : log2(N), 필요 노드 개수 : 2*(N-1);
// 데이터의 갯수(N)가 2의 제곱꼴이 아닐 때 ==> 높이(H) = ⌈log2(N)⌉ (올림), 필요 노드의 개수 : 2^(H+1) - 1
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    arr = new int[N + 1];

    int height = ceil(log2(N) + 1);    // 올림
    int tree_size = 1 << (height + 1); // bit 연산 (제곱)
    tree = new int[tree_size];
    lazy = new int[tree_size];
    init(1, 1, N); // 1~N 까지의 리프노드를 가지는 세그먼트 트리 생성, 1번 인덱스 부터 사용

    return 0;
}