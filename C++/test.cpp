#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++)
    {
            auto itr = array.begin() + (commands[i][0] - 1);
            auto itr2 = array.begin() + (commands[i][1] - 1);
            vector<int> tmp;
            tmp.assign(itr, itr2);
            sort(tmp.begin(), tmp.end());
            answer.push_back(*(tmp.begin() + commands[i][2] - 1));     
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    vector <int> arr = {1, 5, 2, 6, 3, 7, 4};
    vector < vector< int>> commands = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
        vector <int> tmpAnswer = solution(arr, commands);

    
    for(int i = 0; i < tmpAnswer.size(); i++)
    {
        cout<<tmpAnswer[i]<<" "<<endl;
    }
    
    return 0;
}
