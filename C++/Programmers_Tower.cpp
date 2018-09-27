#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> heights, answer, tmpIdx, tmp;
    heights = {6, 9, 5, 7, 4};
    vector<int>::reverse_iterator rItr = heights.rbegin();
    vector<int>::reverse_iterator reItr = heights.rbegin();
    int qtt_heights = heights.size();
    answer.assign(qtt_heights, 0);

    //reverse_iterator 출력
    // for (int i = 0; i < qtt_heights; i++)
    // {
    //     cout << *(rItr + i) << endl;
    // }

    for (int i = 0; i < qtt_heights; i++)
    {
        int tmpHigh = *(rItr + i);

        for (int j = i + 1; j < qtt_heights; j++)
        {
            int reTower = *(reItr + j);
            if (tmpHigh < reTower && reItr != heights.rend())
            { // 수신되었을때
                answer[qtt_heights - i - 1] = qtt_heights - j;
                break;
            }
        }
    }

    cout << "Answer : ";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer.at(i) << "  ";
    }
    cout << endl;

    cout << "tmp : ";
    for (int i = 0; i < tmp.size(); i++)
    {
        cout << tmp.at(i) << "  ";
    }
    cout << endl;

    cout << "tmpIdx : ";
    for (int i = 0; i < tmpIdx.size(); i++)
    {
        cout << tmpIdx.at(i) << "  ";
    }
    cout << endl;

    return 0;
}
