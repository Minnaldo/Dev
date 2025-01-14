#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int solution(vector<string> lines);

int main(int argc, char const *argv[])
{

    vector<string> lines = {"2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"};

    solution(lines);
    return 0;
}

int solution(vector<string> lines)
{
    int answer = 0;
    int logSize = lines.size();
    string tmpStr;
    vector<float> duration;
    vector<float> startTime;
    vector<vector<string>> log(logSize, vector<string>(2));

    //lines 로그기록 나누기, 띄워쓰기 단위로 나누기
    // hh:mm:ss.sss 0.123s  "응답완료 시간 / 처리시간"
    for (int i = 0; i < logSize; i++)
    {
        stringstream ss(lines[i]);
        ss >> tmpStr;
        ss >> log[i][0];
        ss >> log[i][1];

        duration.push_back(stof(log[i][1]));
    }
    //TODO: 시간을 초로 바꾸기
    //출력
    for (int i = 0; i < logSize; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << log[i][j] << "   ";
        }
        cout << endl;
    }

    for (int i = 0; i < duration.size(); i++)
    {
        cout << duration[i] << endl;
        cout << "Start Time : " << startTime[i] << endl;
    }

    return answer;
}