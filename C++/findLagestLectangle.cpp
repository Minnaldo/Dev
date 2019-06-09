#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 *
 */

using namespace std;

int min(int &a, int &b) { return a < b ? a : b; }

int solution(int n, int m)
{
    int answer = 0;
    vector<vector<int>> arr(n, vector<int>(m, 0));

    // data input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // solve
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
                continue;

            if (arr[i][j] == 1)
            {
                arr[i][j] = min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1])) + 1;
                answer = answer > arr[i][j] ? answer : arr[i][j];
            }
        }
    }

    for (vector<int> vec : arr)
    {
        for (int aa : vec)
        {
            cout << aa << " ";
        }
        cout << endl;
    }

    return answer * answer;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    int n = 1, m = 1, cnt = 1;

    while (1)
    {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0)
        {
            break;
        }
        else
        {
            cout << cnt << " : ";
            cout << solution(n, m) << endl;
            cnt++;
        }
    }
    return 0;
}