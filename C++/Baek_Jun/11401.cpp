#include <iostream>

// 곱셈의 역원을 이용한다
using namespace std;

// int arr[][];

int solution(int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            // arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % 1000000007;
        }
    }

    // return arr[n][k] % 1000000007
}

int solution2(int n, int k)
{
    if (k == 0 || n == k)
        return 1;

    return solution2(n - 1, k) + solution2(n - 1, k - 1);
}

int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);

    // for (int i = 0; i <= n; i++)
    //     arr[i][0] = arr[i][i] = 1;

    // int ans = solution(n, k);
    int ans = solution2(n, k);

    printf("%d\n", ans);
    return 0;
}