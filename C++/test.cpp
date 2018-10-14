<<<<<<< HEAD
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    // auto itr = array.begin()
    cout<<commands.size();
    for (int i = 0; i < commands.size(); i++)
    {
        // if (commands[i][0] != commands[i][1])
        // {
            auto itr = array.begin() + (commands[i][0] - 1);
            auto itr2 = itr + (commands[i][1] - 1);
            vector<int> tmp;
            tmp.assign(itr, itr2);
            sort(tmp.begin(), tmp.end());
            answer.push_back(*(tmp.begin() + commands[i][2] - 1));
        // }
        // else
        // {
        //     answer.push_back(*(array.begin() + commands[i][0] - 1));
        // }
    }

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer.at(i) << "  ";
    }
    cout << endl;
=======
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
>>>>>>> ad4b6da2c458c163bacec1f6e6dc7950f0a483fa
    return answer;
}

int main(int argc, char const *argv[])
{
<<<<<<< HEAD
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

    solution(array, commands);
=======
    vector <int> arr = {1, 5, 2, 6, 3, 7, 4};
    vector < vector< int>> commands = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
        vector <int> tmpAnswer = solution(arr, commands);

    
    for(int i = 0; i < tmpAnswer.size(); i++)
    {
        cout<<tmpAnswer[i]<<" "<<endl;
    }
    
>>>>>>> ad4b6da2c458c163bacec1f6e6dc7950f0a483fa
    return 0;
}
