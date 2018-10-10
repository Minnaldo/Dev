#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> maps);
vector<int> findRoad(vector<vector<int>> maps, int xpos, int ypos);

int main(int argc, char const *argv[])
{
    vector<vector<int>> maps = {{1, 0, 1, 1, 1},
                                {1, 0, 1, 0, 1},
                                {1, 0, 1, 1, 1},
                                {1, 1, 1, 0, 1},
                                {0, 0, 0, 0, 1}};
    // int result = solution(maps);

    cout<<maps[5][4];

    // cout << "Result : " << result << endl;
    return 0;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    

try
{
    cout<<maps[5][5]<<endl;
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}


    return answer;
}