#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> dp;
vector<int> arr;

int min(int &a, int &b) { return a < b ? a : b; }

// 행렬끼리 곱셈의 횟수 중 가장 작은 횟수를 리턴한다
int calc()
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            int k = i + j;
            dp[j][k] = INT32_MAX; // 최솟값을 구하기 전 최댓값으로 초기화, 얼마나 나올지 모르기 때문에 정수형 최대크기로 초기화 한다.

            // j번째 행렬부터 k번째 행렬까지의 연산 횟수를 구한다.
            for (int L = j; L <= k - 1; L++)
            {
                // TODO need to know this recursion formular
                int tmp = dp[j][L] + dp[L + 1][k] + (arr[j - 1] * arr[L] * arr[k]);
                // arr[j-1], arr[k]의 이유 --> arr[j-1]은 첫번째 행렬의 행의 수, arr[k]는 마지막 행렬의 열의 수
                dp[j][k] = min(tmp, dp[j][k]);
            }
        }
    }

    return dp[1][n - 1];
}

int main(int argc, char const *argv[])
{
    n = 5;

    dp.assign(n, vector<int>(n, 0));
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(7);
    arr.push_back(5);
    arr.push_back(30);

    cout << calc() << endl;

    return 0;
}