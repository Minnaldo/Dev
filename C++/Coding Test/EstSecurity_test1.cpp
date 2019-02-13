#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &ranks)
{
    int answer = 0;
    sort(ranks.begin(), ranks.end());
    int maxVal = *(max_element(ranks.begin(), ranks.end()));
    // cout << maxVal << endl;

    vector<pair<int, int>> temp;

    for (int i = 0; i <= maxVal; i++)
    {
        int Count = count(ranks.begin(), ranks.end(), i);
        // cout << " I : " << i << "  Count : " << Count << endl;
        temp.push_back(make_pair(i, Count));
    }

    int tmpVecSize = temp.size();
    for (int i = 0; i < tmpVecSize; i++)
    {
        if (temp[i].first + 1 == temp[i + 1].first && temp[i + 1].second != 0)
        {
            answer += temp[i].second;
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<int> ranks = {3, 4, 3, 0, 2, 2, 3, 0, 0};    //5

    int answer = solution(ranks);
    cout << "Answer : " << answer << endl;
    return 0;
}