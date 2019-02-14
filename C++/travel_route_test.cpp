#include <iostream>
#include <stack>
#include <string>
#include <vector>

/** 여행경로_프로그래머스 ( https://programmers.co.kr/learn/courses/30/lessons/43164 )
 *  TODO need to review and solve the problem
 */

using namespace std;

bool visit[10000]; //방문 여부를 확인하는 배열

void DFS(vector<vector<string>> &tickets, int idx)
{
    stack<int> idxStack;
    idxStack.push(idx);
    visit[idxStack.top()] = true;
    int vecSize = tickets.size();
    int flag = 0;
    while (!idxStack.empty())
    {
        int current = idxStack.top();
        for(int i = 0; i<vecSize; i++)
        {
            if(!visit[i] && tickets[i][0] == tickets[current][1])
            {
                flag++;
            }
        }

        idxStack.pop();
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    int ticketSize = tickets.size();

    for (int i = 0; i < ticketSize; i++)
    {
        if (tickets[i][0] == "ICN")
        {
            // start dfs
            DFS(tickets, i);
        }
    }

    vector<string> answer;
    return answer;
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
