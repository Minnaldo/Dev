#include <string>
#include <vector>
#include <iostream>
<<<<<<< HEAD
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
=======

using namespace std;

int solution(vector<vector<int>> maps);
int findRoad(vector<vector<int>> maps, int xpos, int ypos, int xLen, int yLen);

int main(int argc, char const *argv[])
{
    vector<vector<int>> maps1 = {{1, 0, 1, 1, 1},
                                 {1, 0, 1, 0, 1},
                                 {1, 0, 1, 1, 1},
                                 {1, 1, 1, 0, 1},
                                 {0, 0, 0, 0, 1}};


try
{
    cout<< maps1.at(5).at(1);
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}

// cout<< maps1.at(5).at(1);
    
    return 0;
>>>>>>> d2bf261eb4a89507fffa424a6bfd93f44657cd09
}