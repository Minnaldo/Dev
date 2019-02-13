#include <iostream>
#include <vector>
#include <algorithm>

/** K번째 수 프로그래머스 ()
 *  * Quick_Select 를 이용하여 풀 수도 있다.
 *  * 두 배열을 오름차순 정렬이 찾아도 된다.
 */

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    int selNum, a, b, k;
    auto itra = array.begin();

    for (int i = 0; i < commands.size(); i++)
    {
        auto itr = array.begin();
        a = commands.at(i).at(0) - 1;
        b = commands.at(i).at(1);
        k = commands.at(i).at(2) - 1;
        vector<int> tmp;
        if (a != b)
        {
            tmp.assign(itr + a, itr + b);
            sort(tmp.begin(), tmp.end());
            selNum = *(tmp.begin() + k);
            answer.push_back(selNum);
        }
        else
        {
            selNum = *(itr + a);
            answer.push_back(selNum);
        }
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    vector<int> tmpAnswer = solution(arr, commands);

    for (int i = 0; i < tmpAnswer.size(); i++)
    {
        cout << tmpAnswer[i] << " ";
    }
    cout << endl;
    return 0;
}
