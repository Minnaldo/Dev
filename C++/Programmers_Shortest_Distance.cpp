#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> maps);
int findRoad(vector<vector<int>> maps, int xpos, int ypos, int xLen, int yLen);

int main(int argc, char const *argv[])
{
    vector<vector<int>> maps1 = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
<<<<<<< HEAD

=======
>>>>>>> c7ae2091ec98e34d7ab2cfa5243797b8924ed914
    vector<vector<int>> maps2 = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}};

    // int result1 = solution(maps1);
    // cout << "Result 1 : "<< result1 << endl;
    int result2 = solution(maps2);
    cout << "Result 2 : " << result2 << endl;
    return 0;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int xpos = 0;
    int ypos = 0;

    int yLen = maps.size();
    int xLen = maps.at(0).size();

    //기본 위치가 있으므로 1
    int cnt = 1;

    // X => 상하, Y=> 좌우
    while (true)
    {
        cout << "Xpos : " << xpos << "   ypos : " << ypos << endl;
        if (xpos < xLen && ypos < yLen && xpos >= 0 && ypos >= 0)
        {
            if (maps[xpos + 1][ypos] == 1)
            {
                //Right
                cout << "Move Down" << endl;
                cnt++;
                maps[xpos][ypos] = 0;
                xpos++;
            }
            else if (maps[xpos][ypos + 1] == 1)
            {
                //Down
                cout << "Move Right" << endl;
                cnt++;
                maps[xpos][ypos] = 0;
                ypos++;
            }
            else if (maps[xpos - 1][ypos] == 1)
            {
                //Up
                cout << "Move Up" << endl;
                cnt++;
                maps[xpos][ypos] = 0;
                xpos--;
            }
            else if (maps[xpos][ypos - 1] == 1)
            {
                //Left
                cout << "Move Left" << endl;
                cnt++;
                maps[xpos][ypos] = 0;
                ypos--;
            }
            else
            {
                //모든 방향이 0
                cout << "No more way" << endl;
                cnt = (-1);
                return cnt;
            }
        }

        if (xpos == (xLen - 1) && ypos == (yLen - 1))
        {
            cout << "The end" << endl;
            return cnt;
        }
    }
}