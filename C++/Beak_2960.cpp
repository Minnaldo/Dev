#include <iostream>

using namespace std;

/** 에라토스 테네스의 체 백준_2960 (https://www.acmicpc.net/problem/2960)
 *  * 에라토스 테네스의 체 에서 K번째 지워지는 수 찾기
 *  * 에라토스 테네스의 체 (https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4)
 *  * 지울 때 마다 cnt변수를 통해 카운트를 하여 알아낸다
 */

int solution(int n, int k, int *arr)
{
    int cnt = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; i * j <= n; j++)
        {
            if (arr[i * j] != 0)
            {
                arr[i * j] = 0;
                cnt++;

                if (cnt == k)
                {
                    return i * j;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int *arr = new int[n + 1];

    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    cout << solution(n, k, arr) << endl;
    return 0;
}