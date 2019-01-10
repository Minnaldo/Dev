#include <iostream>
#include <string>
#include <vector>

using namespace std;

// dp[n] = n일째 남아있는 밀가루 양
int dp[100001];

int max(int &a, int &b)
{
    return a > b ? a : b;
}

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
    int answer = 0;

    int tmpStock = stock;

    auto dItr = dates.begin();
    auto sItr = supplies.begin();

    for (int i = 1; i <= k; i++)
    {
        if (*dItr - tmpStock < 0)
        {
            dp[*dItr] = tmpStock - *dItr + *sItr;
            answer++;
        }
        else if()
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<int> dates = {4, 10, 15};
    vector<int> supplies = {20, 5, 10};

    cout << solution(4, dates, supplies, 30) << endl;
    return 0;
}