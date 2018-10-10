#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> maps);
int findRoad(vector<vector<int>> maps, int xpos, int ypos, int xLen, int yLen);

int main(int argc, char const *argv[])
{
    vector<vector<int>> maps = {{1, 0, 1, 1, 1},
                                {1, 0, 1, 0, 1},
                                {1, 0, 1, 1, 1},
                                {1, 1, 1, 0, 1},
                                {0, 0, 0, 0, 1}};
    int result = solution(maps);

    cout << "Result : " << result << endl;
    return 0;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int xpos, ypos = 0;

    int xLen = maps.size();
    int yLen = maps.at(0).size();

    answer = findRoad(maps, xpos, ypos, xLen, yLen);

    return answer;
}

int findRoad(vector<vector<int>> map, int xpos, int ypos, int xLen, int yLen)
{
    int cnt = 0;
    if (xpos != xLen && ypos != yLen)
    {
        if (xpos < xLen && ypos < yLen)
        {
            int tmpR = map[xpos + 1][ypos];
            int tmpL = map[xpos - 1][ypos];
            int tmpU = map[xpos][ypos - 1];
            int tmpD = map[xpos][ypos + 1];

            if (tmpR == 1)
            {
                //Right
                cout<<"Move Right"<<endl;
                map[xpos][ypos] = 0;
                xpos++;
                cnt++;
                findRoad(map, xpos, ypos, xLen, yLen);
            }
            else if (tmpD == 1)
            {
                //Down
                cout<<"Move Down"<<endl;
                map[xpos][ypos] = 0;
                ypos++;
                cnt++;
                findRoad(map, xpos, ypos, xLen, yLen);
            }
            else if (tmpU == 1)
            {
                //Up
                cout<<"Move UP"<<endl;
                map[xpos][ypos] = 0;
                ypos--;
                cnt++;
                findRoad(map, xpos, ypos, xLen, yLen);
            }
            else if (tmpD == 1)
            {
                //Left
                cout<<"Move Left"<<endl;
                map[xpos][ypos] = 0;
                xpos--;
                cnt++;
                findRoad(map, xpos, ypos, xLen, yLen);
            }
            else
            {
                return -1;
            }
        }
    }
    else
    {
        return cnt;
    }
}