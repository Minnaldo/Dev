#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    int opSize = operations.size();
    string str;

    for (int i = 0; i < opSize; i++)
    {
        auto itr = operations[i].begin();

        if (*itr == 'I')
        {
            str = "";
            for (itr = itr + 1; itr < operations[i].end(); itr++)
            {
                str += *itr;
            }
            answer.push_back(stoi(str));
            sort(answer.begin(), answer.end());
        }
        else
        {
            if (answer.size() > 0)
            {
                if (*(itr + 2) == '-')
                {
                    answer.erase(answer.begin());
                }
                else
                {
                    answer.pop_back();
                }
            }
        }
    }

    if (answer.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    else
    {
        vector<int> tmp;
        tmp.push_back(answer.back());
        tmp.push_back(answer.front());
        return tmp;
    }
}

int main(int argc, char const *argv[])
{
    // vector<string> vec = {"I 7", "I 5", "I -5", "D -1"};
    vector<string> vec = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
    vector<int> answerVec = solution(vec);

    int size = answerVec.size();
    for (int i = 0; i < size; i++)
    {
        cout << answerVec[i];
    }
    cout << endl;

    return 0;
}
