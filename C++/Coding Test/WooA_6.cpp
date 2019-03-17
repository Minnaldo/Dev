#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int totalTicket, vector<string> logs)
{
    vector<string> answer;
    vector<string> name;
    vector<string> action;
    vector<int> reqtime;
    int logSize = logs.size();

    for (int i = 0; i < logSize; i++)
    {
        int size = logs[i].size();
        int tmpTime = stoi(logs[i].substr(size - 5, 2)) * 60 + stoi(logs[i].substr(size - 2, 2));
        reqtime.push_back(tmpTime);
    }

    for (int i = 0; i < logSize; i++)
    {
        int size = logs[i].size();
        for (int j = 0; j < size; j++)
        {
            int idx = 0;
            if (logs[i][j] == ' ')
            {
                if (idx == 0)
                {
                    name.push_back(logs[i].substr(idx, j));
                    idx = j + 1;
                }
                else
                {
                    action.push_back(logs[i].substr(idx, j - idx));
                    break;
                }
            }
        }
    }
    bool flag = false;
    for (int i = 0; i < logSize; i++)
    {
        if (action[i] == "request")
        {
            if (!flag)
            {
                int curTime = reqtime[i];
                for(int j = i+1; j< reqtime.size(); j++)
                {
                    if(reqtime[j] - curTime < 60)
                    {
                        name.erase[j];
                        action.erase[j];
                        reqtime.erase[j];
                    }
                }


            }
            else
            {
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main(int argc, char const *argv[])
{
    int size = 2000;
    vector<string> logs = {
        "woni request 09:12:29",
        "brown request 09:23:11",
        "brown leave 09:23:44",
        "jason request 09:33:51",
        "jun request 09:33:56",
        "cu request 09:34:02"};

    vector<string> answer = solution(size, logs);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
    return 0;
}