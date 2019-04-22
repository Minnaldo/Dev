#include <algorithm>
#include <iostream>

/**
 *  * 소팅 후 1~3의 최소 공배수
 */

using namespace std;

int arr[5];

int min(int &a, int &b) { return a < b ? a : b; }

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    for (int i = 0; i < 5; i++)
        scanf("%d", &arr[i]);

    int ans = 987654321;
    for (int i = 0; i < 5; i++)
    {
        int tmp = (arr[i % 5] * arr[(i + 1) % 5]) / gcd(arr[i], arr[(i + 1) % 5]);
        int ret = (tmp * arr[(i + 2) % 5]) / gcd(tmp, arr[(i + 2) % 5]);
        int cnt = 0;
        for (int j = 0; j < 5; j++)
        {
            if (ret % arr[j] == 0)
                cnt++;
        }

        if (cnt >= 3)
        {
            ans = min(ans, ret);
        }
    }

    printf("%d\n", ans);

    return 0;
}