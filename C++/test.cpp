#include <iostream>
#include <string>
#include <vector>

/**
 *  ! segFault
 */

using namespace std;

// dp[n] = n일째 남아있는 밀가루 양
int dp[100001];
int idx;

int max(int a, int b, int aIdx, int bIdx)
{
    idx = a > b ? aIdx : bIdx;
    return a > b ? a : b;
}

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
    int answer = 0;
    int tmpStock = stock;
    int dSize = dates.size();
    vector<int> tmpVec;

    dp[1] = stock;

    for (int i = 0; i < dSize; i++)
    {
        // dates[i] 날짜에 얻을 수 있는 밀가루 양
        dp[dates[i]] = tmpStock - dates[i] + supplies[i];

        for (int j = 0; j < dSize; j++)
        {
            // n+1일 ~ n+supplise[n] 사이의 공급받을 수 있는 날짜, dp[dates[]]
            if (dp[i] - dates[j] >= 0)
            {
                tmpVec.push_back(j);
            }
        }

        int tVecSize = tmpVec.size();

        dp[dates[tmpVec[0]]] = dp[i] - dates[tmpVec[0]] + supplies[tmpVec[0]];
        // i 일째 기준으로 버틸 수 있는 날짜에 밀가루 공급받을 경우 중 가장 오래 버틸 수 있는 경우
        for (int k = 1; k < tVecSize; k++)
        {
            dp[dates[tmpVec[k]]] = max((dp[i] - dates[tmpVec[k]] + supplies[tmpVec[k]]), dp[dates[tmpVec[k - 1]]], tmpVec[k], tmpVec[k - 1]);
        }
        answer++;
        if (dp[idx] >= k - 1) // 위에서 구한 dates에 공급을 받았을 때, 저장량이 k-1보다 클 경우 종료
        {
            answer++;
            return answer;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> dates = {4, 10, 15};
    vector<int> supplies = {20, 5, 10};

    cout << solution(4, dates, supplies, 30) << endl;
    return 0;
}