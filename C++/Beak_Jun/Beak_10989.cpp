#include <iostream>

/** 수 정렬하기 3 백준_10989 ( https://www.acmicpc.net/problem/10989 )
 *  * Counting Sort (계수 정렬)을 이용한다
 *  ? 계수정렬 --> 각 수의 갯수를 저정하고 그 수를 갯수만큼 출력
 */

using namespace std;

int arr[10001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N, a;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a;
        arr[a]++;
    }

    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            cout << i << "\n";
        }
    }

    return 0;
}