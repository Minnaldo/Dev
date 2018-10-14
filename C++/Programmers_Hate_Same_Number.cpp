#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int>);

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 1, 3, 3, 0, 1, 1};
    solution(arr);
    return 0;
}

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    auto itr = arr.begin();

    for (itr; itr < arr.end(); itr++)
    {
        if (*itr != *(itr + 1))
        {
            answer.push_back(*itr);
        }
    }

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer.at(i) << " ";
    }
    cout << endl;
}