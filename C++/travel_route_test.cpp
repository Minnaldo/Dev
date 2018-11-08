#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

vector<string> stopOver; //경유지를 저장할 벡터 배열
bool visit[10000];       //방문 여부를 확인하는 배열
int ticketQuantity;      //처음 들어오는 티켓의 갯수를 저장하기 위한 변수
string department;

void bfs(string arrive, vector<vector<string>> ticket)
{
    stopOver.push_back(arrive);
    string current = arrive;
    vector<pair<string, string>> tmpVec;
    //출발지 목록이 될 수 있는 항목을 임시벡터에 저장
    //arrive로 넘겨받은 변수를 출발지로 가진 항목을 찾는다, 후보가 2가지 이상 일 경우 후보배열의 인덱스 1 항목을 비교해 선정
    for (int i = 0; i < ticketQuantity; i++)
    {
        if (!visit[i] && current == ticket[i][0])
        {
            tmpVec.push_back(make_pair(ticket[i][0], ticket[i][1]));
        }
    }
    int tmpIdx;
    if (tmpVec.size() > 1)
    {
        for (int i = 0; i < tmpVec.size() - 1; i++)
        {
            if (tmpVec[i].second.compare(tmpVec[i + 1].second) < 0)
            {
                tmpIdx = i;
            }
            else
            {
                tmpIdx = i + 1;
            }
        }
    }
    else
    {
        tmpIdx = tmpVec.size() - 1;
    }

    department = tmpVec[tmpIdx].second;
    // stopOver.push_back(department);
    // tmpVec.clear();
    if (tmpVec[tmpIdx].second != "\0")
    {
        bfs(department, ticket);
    }

    // for (int i = 0; i < ticketQuantity; i++)
    // {
    //     if (!visit[i] && ticket[i][0] == department)
    //     {
    //         visit[i] = true;
    //     }
    // }
}

vector<string> solution(vector<vector<string>> tickets)
{
    ticketQuantity = tickets.size();
    int tmpIdx;

    vector<pair<string, string>> tmpVec1;
    for (int i = 0; i < ticketQuantity; i++)
    {
        if (tickets[i][0].compare("ICN") == 0)
        {
            //출발지 체크
            tmpVec1.push_back(make_pair(tickets[i][0], tickets[i][1]));
        }
    }

    if (tmpVec1.size() > 1)
    {
        for (int i = 0; i < tmpVec1.size() - 1; i++)
        {
            if (tmpVec1[i].second.compare(tmpVec1[i + 1].second) < 0)
            {
                tmpIdx = i;
            }
            else
            {
                tmpIdx = i + 1;
            }
        }
    }
    else
    {
        tmpIdx = tmpVec1.size() - 1;
    }

    stopOver.push_back(tmpVec1[tmpIdx].first);
    // tmpVec.clear();

    if (!visit[tmpIdx])
    {
        visit[tmpIdx] = true;
        bfs(tickets[tmpIdx][1], tickets);
    }

    return stopOver;
}

int main(int argc, char const *argv[])
{
    vector<string> answer;
    vector<vector<string>> arr = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
    vector<vector<string>> arr2 = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};
    answer = solution(arr2);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
