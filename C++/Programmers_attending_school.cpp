#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

/**
 * * 전체경우의 수 - 특정 지점을 지나는 경우의 수
 * * 전체경우의 수 - 특정 지점을 지나지 않는 경우의 수
 * * N * M 좌표계에서 지날 수 있는 경우의 수 = (N+M)C(N or M)
 */

int arr[100][100];

// 조합을 구하는 함수
int combination(int n, int r)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= r; j++)
        {
            if (i == j || j == 0)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }
    return arr[n][r];
}

int solution(int m, int n, vector<vector<int>> puddles)
{

    int tmp, pudSize = puddles.size();
    //갈 수있는 모든 수 (웅덩이 무시)
    int whole = combination(m + n, n);
    vector<int> tmpVec;

    if (pudSize <= 1)
    {
        int tmp1 = m - puddles[0][0] + 1;
        int tmp2 = n - puddles[0][1] + 1;
        tmpVec.push_back(combination(puddles[0][0] + puddles[0][1], puddles[0][1]));
        tmpVec.push_back(combination(tmp1+tmp2, tmp2));
    }
    else
    {
        tmpVec.push_back(combination(puddles[0][0] + puddles[0][1], puddles[0][1]));
        for (int i = 1; i < pudSize; i++)
        {
            int tmp1 = puddles[i][0] - (puddles[i - 1][0] - 1), tmp2 = puddles[i][1] - (puddles[i - 1][1] - 1);
            tmpVec.push_back(combination(tmp1 + tmp2, tmp2));
        }
    }

    int tVecSize = tmpVec.size();
    for (int i = 0; i < tVecSize; i++)
    {
        whole -= tmpVec[i];
    }
    return whole % 1000000007;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> forbidden = {{2, 2}};
    cout << solution(4, 3, forbidden) << endl;
    return 0;
}