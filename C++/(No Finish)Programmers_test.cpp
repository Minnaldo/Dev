#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> correct(3);

vector<int> solution(vector<int> answers)
{
    int n = answers.size();

    vector<int> people(3);

    vector <int> supo1 = {1, 2, 3, 4, 5};
    vector <int> supo2 ={2, 1, 2, 3, 2, 4, 2, 5};
    vector <int> supo3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    auto itr1 = supo1.begin();
    auto itr2 = supo2.begin();
    auto itr3 = supo3.begin();
    auto ansItr = answers.begin();

    for (ansItr; ansItr < answers.end(); ansItr++)
    {
        if (itr1 != supo1.end())
        {
            if (*itr1 == *ansItr)
            {
                correct[0] += 1;
                itr1++;
            }
        }
        else
        {
            itr1 = supo1.begin();
        }
        if (itr2 != supo2.end())
        {
            if (*itr2 == *ansItr)
            {
                correct[1] += 1;
                itr2++;
            }
        }
        else
        {
            itr2 = supo2.begin();
        }
        if (itr3 != supo3.end())
        {
            if (*itr3 == *ansItr)
            {
                correct[2] += 1;
                itr3++;
            }
        }
        else
        {
            itr3 = supo3.begin();
        }
    }
}

int main(int argc, char const *argv[])
{

    vector<int> answers = {1, 2, 3, 4, 5};
    vector<int> answers1 = {1, 3, 2, 4, 2};

    solution(answers);
    solution(answers1);
}