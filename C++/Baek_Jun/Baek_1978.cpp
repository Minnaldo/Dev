#include <iostream>

/** 소수 찾기 백준_1978 ( https://www.acmicpc.net/problem/1978 )
 *  * 에라토스 테네스의 체를 이용해 소수를 찾고 --> 해당 인덱스가 false이면 소수, true이면 소수 아님
 */

using namespace std;

bool arr[1001];

int main(int argc, char const *argv[])
{
    arr[1] = true;
    for (int i = 2; i <= 1000; i++)
    {
        if (!arr[i])
            for (int j = i * 2; j <= 1000; j += i)
                arr[j] = true;
    }

    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if (!arr[tmp])
            ans++;
    }

    printf("%d\n", ans);
    return 0;
}