#include <iostream>
#include <sstream>

using namespace std;

int dp[1001][1001];
int dir[3][2] = {{-1, 0}, {0, -1}, {-1, -1}};

int max(int a, int b)
{
    return a > b ? a : b;
}

int solution(int **arr, int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int nxt_y = i + dir[k][0];
                int nxt_x = j + dir[k][1];

                if (nxt_y >= 1 && nxt_y <= n && nxt_x >= 1 && nxt_x <= m)
                {
                    dp[i][j] = max(arr[i][j] + dp[nxt_y][nxt_x], dp[i][j]);
                }
            }
        }
    }

    return dp[n][m];
}

int main(int argc, char const *argv[])
{
    string str  = "3 4 1 2 3 4 0 0 0 5 9 8 7 6";    //31
    string str2 = "1 2 1 1";    //2
    stringstream ss;
    ss.str(str);
    int n, m;
    ss >> n >> m;

    int **arr = new int *[n + 1];
    for (int i = 1; i <= n; i++)
    {
        arr[i] = new int[m + 1];
        for (int j = 1; j <= m; j++)
        {
            int tmp;
            ss >> tmp;
            arr[i][j] = tmp;
        }
    }

    dp[1][1] = arr[1][1];
    cout << solution(arr, n, m) << endl;

    return 0;
}