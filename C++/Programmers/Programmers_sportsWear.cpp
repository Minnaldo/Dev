#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int tmp = n;

    for (int i = 0; i < lost.size(); i++)
    {
        auto itr = find(reserve.begin(), reserve.end(), lost[i]);
        if (itr != reserve.end())
        {
            reserve.erase(itr);
            lost[i] = -1;
        }
    }

    for (int lo : lost)
        cout << lo << " ";
    cout << endl;

    for (int i = 0; i < lost.size(); i++)
    {
        if (lost[i] > 0 && lost[i] <= 30)
        {
            auto itr = find(reserve.begin(), reserve.end(), lost[i] - 1);
            auto itr2 = find(reserve.begin(), reserve.end(), lost[i] + 1);

            if (itr == reserve.end() && itr2 == reserve.end())
            {
                tmp--;
            }
            else // 주변 학생중 여분이 있을 때
            {
                if (itr != reserve.end())
                {
                    *itr = -1;
                }
                else if (itr != reserve.end())
                {
                    *itr = -1;
                }
            }
            lost[i] = -1;
        }
    }

    return tmp;
}

int main(int argc, char const *argv[])
{
    int n;
    vector<int> lost, reserve;
    lost = {2};
    reserve = {2};
    n = 3;
    cout << solution(n, lost, reserve) << endl;
    return 0;
}