#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

/**
 * * 여행경롤를 탐색하는 알고리즘
 * * DFS를 이용하자 (인접 리스트 DFS)
 * * LG CNS Code Monster와 비슷하다
 *  */

stack<string> s;
vector<string> stopOver; //경유지를 저장할 벡터 배열
bool visit[10000];       //방문 여부를 확인하는 배열
int ticketQuantity;      //처음 들어오는 티켓의 갯수를 저장하기 위한 변수

void dfs(string arrive, vector<vector<string>> ticket)
{
    s.push(arrive);

    // string current = s.top();
    string current = arrive;
    for (int i = 0; i < ticketQuantity; i++)
    {
        if (!visit[i] && current == ticket[i][0])
        {
            // s.push(ticket[i][0]);
            stopOver.push_back(ticket[i][0]);
            stopOver.push_back(ticket[i][1]);
            visit[i] = true;
            dfs(ticket[i][0], ticket);
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    // visit = new bool[ticketQuantity];
    ticketQuantity = tickets.size();
    // s.push(tickets[0][0]); // push ICN (push department)
    stopOver.push_back(tickets[0][0]);
    stopOver.push_back(tickets[0][1]);
    visit[0] = true;

    for (int i = 0; i < ticketQuantity; i++)
    {
        if (!visit[i])
        {
            dfs(tickets[i][1], tickets);
        }
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
        cout << answer[i];
    }
    cout << endl;

    return 0;
}
