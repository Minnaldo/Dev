#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 *  * 숫자의 범위 : 000 ~ 999, 이들을 모두 판별
 */

using namespace std;

vector<string> arr;

void func()
{
    string temp = "";

    for (int i = 0; i <= 999; i++)
    {
        if ((i / 100) < 1)
        {
            if ((i / 10) >= 1)
            {
                temp += ("0" + to_string(i));
            }
            else
            {
                temp += ("00" + to_string(i));
            }
        }
        else
        {
            temp += to_string(i);
        }
    }
    arr.push_back(temp);
}

int solution(vector<vector<int>> baseball)
{
    int answer = 0;
    int bSize = baseball.size();
    func();
    int arrSize = arr.size();
    vector<int> temp;
    // compare baseball[i][0] to femp
    // how to use the baseball vector

    for (int i = 0; i < bSize; i++)
    {
        temp.push_back((baseball[i][1] * 3) + baseball[i][2]);
    }




    return answer;
}

int main(int argc, char const *argv[])
{

    vector<vector<int>> arr = {{{123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1}}};

    cout << solution(arr) << endl;
    return 0;
}
