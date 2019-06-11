#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, t;

int max(int &a, int &b) { return a > b ? a : b; }

// calculate the mass of cheess
int calc(vector<vector<int>> &cheese)
{
    // get quantity of cheese
    int ret = 0;
    vector<vector<bool>> visit(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
        }
    }

    return ret;
}

int solution(vector<vector<int>> cheese)
{
    int ans = 0;
    // the range of taste of cheese
    for (int i = 1; i <= 100; i++)
    {
        // write solution
        // 범위기반 for문에서 내용을 수정하는 방법
        for (vector<int> &aa : cheese)
            for (int &taste : aa)
            {
                if (taste == i)
                    taste = 0;
            }

        ans = max(ans, calc(cheese));
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n;

        vector<vector<int>> cheese(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> cheese[i][j];
            }
        }

        cout << "#" << tc << " " << solution(cheese) << endl;
    }
    return 0;
}