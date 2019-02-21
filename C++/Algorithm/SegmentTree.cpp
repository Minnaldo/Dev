#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

/** 세그먼트 트리 (Segment tree) :: https://wkdtjsgur100.github.io/segment-tree/
 *  * root idx = 1, child idx ==> (p_idx * 2), (p_idx * 2) + 1
 *  백준 구간 합 구하기 ( https://www.acmicpc.net/problem/2042 )
 */

using namespace std;

int *tree, *arr;

int seg_tree_init(int idx, int start, int end)
{
    if (start == end)
        tree[idx] = arr[start];
    else
        tree[idx] = seg_tree_init(idx * 2 + 1, start, (start + end) / 2) + seg_tree_init(idx * 2 + 2, (start + end) / 2 + 1, end);

    return tree[idx];
}

// Search section [start, end], sum scope [left, right]
int segT_sum(int idx, int start, int end, int left, int right)
{
    if (end < left || right < start) // 범위가 겹치지 않을경우
        return 0;
    else if (left <= start && end <= right) // 탐색범위가 합구간에 속해있는 경우
        return tree[idx];
    else
    {
        int mid = (start + end) / 2;
        return segT_sum(2 * idx + 1, start, mid, left, right) + segT_sum(2 * idx + 1, mid + 1, end, left, right);
    }
}

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

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    arr = new int[N + 1];
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    int tree_height = ceil(log2(N));        // 올림
    int tree_size = 1 << (tree_height + 1); // bit 연산 (제곱)
    tree = new int[tree_size];
    seg_tree_init(0, 0, N - 1);

    return 0;
}