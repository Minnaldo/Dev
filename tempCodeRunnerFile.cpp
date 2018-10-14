#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    auto itr = array.begin();
    auto itr2 = array.begin();
    
    for(int i = 0; i < commands.size(); i++)
    {
            itr = itr + commands[i][0];
            itr2 = itr2 + commands[i][1];
            sort(itr,itr2);
            answer.push_back(*(itr+commands[i][2]));
    }
    
    
    for(int i = 0; i < answer.size(); i++)
    {
        cout<<answer.at(i)<<"  ";
    }
    cout<<endl;
    return answer;
}

int main(int argc, char const *argv[])
{
    vector <int> array = {1, 5, 2, 6, 3, 7, 4};
    vector <vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    return 0;
}
