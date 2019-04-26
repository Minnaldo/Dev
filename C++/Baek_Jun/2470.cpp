#include <cstring>
#include <iostream>
#include <string>

/** 조합 백준_2407 ( https://www.acmicpc.net/problem/2407 )
 *  * 100 C 100 의 경우 제대로된 값이 출력되지 않는다 이를 수정해야 한다
 *  * big intager 를 써야한다
 */

using namespace std;

string arr[101][101];

string solution(int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            arr[i][j] = to_string(stoull(arr[i - 1][j]) + stoull(arr[i - 1][j - 1]));
        }
    }

    return arr[n][k];
}

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= 100; i++)
        arr[i][0] = arr[i][i] = to_string(1);

    cout << solution(n, m) << endl;
    return 0;
}