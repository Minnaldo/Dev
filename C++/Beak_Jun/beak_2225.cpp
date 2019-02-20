#include <algorithm>
#include <iostream>
#include <vector>

/** 합 분해 백준_2225 ( https://www.acmicpc.net/problem/2225 )
 *  * 중복순열 이용 : 메모리 초과 --> 다른 방법이 필요하다
 */

using namespace std;

int cnt, N;

int permutation(int *arr, int n, int r, int depth)
{
    if (depth == r)
    {
        int tmp = 0;
        for (int i = 0; i < r; i++)
        {
            tmp += arr[i];
        }
        if (tmp == N)
            return 1;
    }

    for (int i = 0; i < n; i++)
    {
        arr[depth] = i;
        cnt = (cnt % 1000000000) + permutation(arr, n, r, depth + 1);
    }

    return cnt % 1000000000;
}

int solution(int N)
{
    return 1;
}

int main(int argc, char const *argv[])
{
    int K;
    // cin >> N >> K;
    N = 20, K = 2;
    int *arr = new int[N + 1];
    for (int i = 0; i <= N; i++)
    {
        arr[i] = i;
    }

    cout << permutation(arr, N + 1, K, 0) << endl;

    cout << solution(N) << endl;

    return 0;
}