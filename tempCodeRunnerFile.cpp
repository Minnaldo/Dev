#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int solution(int m, int n, vector<string> board);

int main(int argc, char const *argv[])
{
    solution(4, 5, {"CCBDE", "AAADE", "AAABF", "CCBBF"});
    return 0;
}


int solution(int m, int n, vector<string> board){
    int answer = 0;

    vector < vector<string> > map;
    
    
    for(int i = 0; i < board.size(); i++)
    {
        vector <string> row;
        row.push_back(board[i]);

        map.push_back(row);
    }
    

    return answer;
}