#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    vector<string> used;
    answer.push_back(0);
    answer.push_back(0);

    auto itr = words.begin();
    int pIdx = 1, circular = 0;

    while (true)
    {
        if (find(used.begin(), used.end(), *itr) != used.end())
        {
            answer[0] = pIdx;
            answer[1] = circular;
            break;
        }
        else if ((*(itr - 1)).back() != (*itr).front()) // 끝말 잇기를 진행하지 못할 단어를 말하였을 때
        {
            answer[0] = pIdx;
            answer[1] = circular;
            break;
        }
        else
        {
            used.push_back(*itr);
        }

        if (pIdx == n)
        {
            circular++;
            pIdx = 1;
        }
        itr++;
        pIdx++;

        if (itr == words.end() - 1)
        {
            // itr = words.begin();
            answer[0] = 0;
            answer[1] = 0;
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<string> words = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};

    vector<int> ans = solution(3, words);

    for (int aa : ans)
    {
        cout << aa << "\t";
    }
    cout << endl;
    return 0;
}