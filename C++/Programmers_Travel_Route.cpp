#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

/**
 * * 여행경롤를 탐색하는 알고리즘
 * * DFS를 이용하자 (인접 리스트 DFS)
 * * BFS도 이용 가능할 듯
 * * LG CNS Code Monster와 비슷하다
 *  */

stack<string> s;
vector<string> stopOver; //경유지를 저장할 벡터 배열
bool visit[10000];       //방문 여부를 확인하는 배열
int ticketQuantity;      //처음 들어오는 티켓의 갯수를 저장하기 위한 변수

void dfs(string arrive, vector<vector<string>> ticket)
{
    stopOver.push_back(arrive);
    string current = arrive;
    for (int i = 0; i < ticketQuantity; i++)
    {
        if (!visit[i] && current == ticket[i][0])
        {
            visit[i] = true;
            dfs(ticket[i][1], ticket);
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    ticketQuantity = tickets.size();
    string department;
    int tmpIdx;

    for(int i =0; i<ticketQuantity; i++)
    {
        for(int j = i; j<ticketQuantity; i++)
        {
            if(tickets[i][0] == tickets[j][0] )
            {
                if(tickets[i][0].compare(tickets[j][0]) < 0 )
                {
                    department = tickets[i][0];
                    tmpIdx = i;
                }
                else
                {
                    department = tickets[j][0];
                    tmpIdx = j;
                }
            }
        }
    }

    stopOver.push_back(department);
    if(!visit[tmpIdx])
    {
        visit[tmpIdx] = true;
        dfs(tickets[tmpIdx][1], tickets);
    }

    return stopOver;
}

int main(int argc, char const *argv[])
{
    vector<string> answer;
    vector<vector<string>> arr = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
    answer = solution(arr);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
