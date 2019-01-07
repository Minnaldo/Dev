#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;

    vector<vector<int>> temp(3, vector<int>(10000, 0));

    vector<int> aa = {1, 2, 3, 4, 5};
    vector<int> bb = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> cc = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    auto aaItr = aa.begin();
    auto bbItr = bb.begin();
    auto ccItr = cc.begin();

    int ansSize = answers.size();
    int aaCnt = 0, bbCnt = 0, ccCnt = 0;
    for (int i = 0; i < ansSize; i++)
    {
        if (answers[i] == *aaItr)
        {
        }
    }

    answer.push_back(aaCnt);
    answer.push_back(bbCnt);
    answer.push_back(ccCnt);

    sort(answer.begin(), answer.end());
    return answer;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 3, 2, 4, 2};
    vector<int> answer = solution(arr2);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}