#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

//Queue를 이용한 방법도 있음

using namespace std;

int main(int argc, char const *argv[])
{
    //각 배포일이 가까운 순서대로 완료되는 작업의 갯수 리턴
    //sppeds : 개발 속도, progresses : 작업 진도
    vector<int> progresses, speeds, answer, finishTime;

    progresses = {93, 30, 55};
    speeds = {1, 30, 5};

    for (int i = 0; i < progresses.size(); i++)
    {
        double remainProgress = 100 - progresses.at(i);
        int tmp = ceil(remainProgress / speeds.at(i)); // ceil : 올림
        finishTime.push_back(tmp);
    }

    for (int i = 1; i < finishTime.size(); i++)
    {
        if (finishTime.at(i - 1) > finishTime.at(i))
        {
            finishTime.at(i) = finishTime.at(i - 1);
        }
    }

    stable_sort(finishTime.begin(), finishTime.end());

    int idx = 0;
    while (!finishTime.empty())
    {
        int tmpVal = finishTime.at(idx);
        int cnt = count(finishTime.begin(), finishTime.end(), tmpVal);
        answer.push_back(cnt);
        finishTime.erase(finishTime.begin(), finishTime.begin() + cnt);
        idx = 0;
    }

    cout << "Finish Time : ";
    for (int i = 0; i < finishTime.size(); i++)
    {
        cout << finishTime.at(i) << "  ";
    }
    cout << endl;
    cout << "Answer : ";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer.at(i) << "  ";
    }
    cout << endl;

    return 0;
}
