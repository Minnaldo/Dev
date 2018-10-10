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

int solution(int m, int n, vector<string> board)
{
    int answer = 0;

    vector<vector<string>> map;

    for (int i = 0; i < board.size(); i++)
    {
        vector<string> row;
        row.push_back(board[i]);
        map.push_back(row);
        row.clear();
    }

    mapSearch(map);

    for (int i = 0; i < map.size(); i++)
    {

        for (int j = 0; j < map[i].size(); j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }

    return answer;
}

bool mapSearch(vector<vector<string>> map, int xpos, int ypos)
{
    string tmp = map[xpos][ypos];
    string tmp1 = map[xpos + 1][ypos];
    string tmp2 = map[xpos][ypos + 1];
    string tmp3 = map[xpos + 1][ypos + 1];

    if (tmp && tmp1 && tmp2 && tmp3)
    {
        return true;
    }
    return false;
}