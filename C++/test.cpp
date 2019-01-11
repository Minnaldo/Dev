#include <iostream>
#include <string>
#include <vector>

using namespace std;

// dp[n] = n일째 남아있는 밀가루 양
int dp[100001];

int max_Dates(int a, int b, int aidx, int bidx)
{
    return a > b ? aidx : bidx;
}

int max(int &a, int &b)
{
    return a > b ? a : b;
}

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
    int answer = 0;
    int tmpStock = stock;
    int dSize = dates.size();
    vector<int> tmpVec;

    dp[1] = stock;

    for (int i = 1; i <= dSize; i++)
    {
        dp[dates[i]] = tmpStock - dates[i] + supplies[i];

        for (int j = i + 1; j <= dSize; j++)
        {
            // n+1일 ~ n+supplise[n] 사이의 공급받을 수 있는 날짜
            if (dp[i] > dates[j])
            {
                tmpVec.push_back(j);
            }
        }

        int tVecSize = tmpVec.size();
        int idx = 0;
        int tmpStk = 0;
        int todayStock = dp[i];
        for (int k = 0; k < tVecSize - 1; k++)
        {
            // 오늘 공급 받았을때 버틸 수 있는 공급일 배열 : tmpVec
            tmpStk = max(todayStock - dates[tmpVec[k]] + supplies[tmpVec[k]], tmpStk);
            idx = max_Dates(todayStock - dates[tmpVec[k]] + supplies[tmpVec[k]], todayStock - dates[tmpVec[k+1]] + supplies[tmpVec[k+1]], tmpVec[k], tmpVec[k + 1]); // 가장 오랫동안 버틸 수 있는 공급일자의 인덱스
        }

        dp[idx] = tmpStk;
        answer++;

        if (dp[idx] >= k - 1) // 위에서 구한 dates에 공급을 받았을 때, 저장량이 k-1보다 클 경우 종료
        {
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