#include <iostream>

using namespace std;

int answer, n;

int dfs(int **arr, int x, int y, int flag)
{
    // 다음칸의 값이 현재칸 +1 보다 클때,
    if (flag == 1) // 우
    {
        if (arr[x - 1][y] + 2 > arr[x][y])
            return 0;
    }
    else if (flag == 2) // 좌
    {
        if (arr[x + 1][y] + 2 > arr[x][y])
            return 0;
    }
    else if (flag == 3) // 상
    {
        if (arr[x][y - 1] + 2 > arr[x][y])
            return 0;
    }
    else // 하
    {
        if (arr[x][y + 1] + 2 > arr[x][y])
            return 0;
    }

    if ((x == 0 || x == n - 1) && (y == 0 || y == n - 1))
        answer += arr[x][y];
    else
    {
        dfs(arr, x + 1, y, 1); // 오른쪽
        dfs(arr, x - 1, y, 2); // 왼쪽
        dfs(arr, x, y + 1, 3); // 위쪽
        dfs(arr, x, y - 1, 4); // 아래쪽
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);

        int **arr = new int *[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
    }
    return 0;
}