#include <iostream>

/** X보다 작은 수 백준_10871 ( https://www.acmicpc.net/problem/10871 )
 *  * X보다 작은수를 찾는 문제
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N, X;
    cin >> N >> X;

    int *arr = new int[N];
    int *tmp = new int[N];
    int idx = 0;
    // 입력을 받으며 비교를 한다
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] < X)
            tmp[idx++] = arr[i];
    }

    for (int i = 0; i < idx; i++)
    {
        cout << tmp[i] << " ";
    }

    return 0;
}