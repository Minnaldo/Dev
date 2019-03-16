#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool solution(vector<vector<int>> lands, vector<vector<int>> wells, vector<int> point)
{
    bool answer = true;

    int landsSize = lands.size();
    int wellsSize = wells.size();

    int x1 = point[0], x2 = point[2], y1 = point[1], y2 = point[3];

    for (int i = 0; i < landsSize; i++)
    {
        // x 좌표 포함 X
        if ((lands[i][2] < x1 || x2 < lands[i][0]) || (lands[i][3] < y1 || y2 < lands[i][1]))
        {
            answer = false;
        }
        else
        {
            answer = true;
        }
    }
    if (answer)
    {
        for (int i = 0; i < wellsSize; i++)
        {
            if ((wells[i][0] > x1 || x2 > wells[i][2]) || (wells[i][1] > y1 || y2 > wells[i][3]))
            {
                answer = true;
            }
            else
            {
                answer = false;
            }
        }
    }

    return answer;
}


int main(int argc, char const *argv[])
{
    vector<vector<int>> lands = {{10, 0, 30, 5}, {0, 30, 20, 50}, {30, 30, 40, 40}};
    vector<vector<int>> wells = {{15, 15, 25, 25}, {40, 10, 50, 20}};
    vector<int> point = {10, 10, 30, 30};

    bool ans = solution(lands, wells, point);

    if (ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}