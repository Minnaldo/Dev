#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    vector<int>::iterator itr = array.begin();
    for (int i = 0; i < commands.size(); i++)
    {
        if (commands.at(i).at(0) != commands.at(i).at(1))
        {
            vector<int> tmp;
            tmp.assign(itr + (commands.at(i).at(0) - 1), itr + (commands.at(i).at(1) - 1));
            sort(tmp.begin(), tmp.end());
            int selNum = *(tmp.begin() + commands.at(i).at(2) - 1);
            answer.push_back(selNum);
        }
        else
        {
            int selNum = *(itr + commands.at(i).at(0) - 1);
            answer.push_back(selNum);
        }
    }

    // for (int i = 0; i < answer.size(); i++)
    // {
    //     cout << answer[i] << " " << endl;
    // }

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    vector<int> tmpAnswer = solution(arr, commands);

    for (int i = 0; i < tmpAnswer.size(); i++)
    {
        cout << tmpAnswer[i] << " ";
    }
    cout << endl;
    return 0;
}
