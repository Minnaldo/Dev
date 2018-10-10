#include <vector>
#include <iostream>

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
}