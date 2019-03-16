#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

/**
 * * 여행경롤를 탐색하는 알고리즘
 *  * 알고리즘 순서 ==> ICN으로 시작하는 티켓을 찾는다 (벡터에 저장이 좋을 듯) (BFS이용)
 *  * 2) 티켓이 여러개면 티켓 도착지를 비교해 알파벳 순서로 사용
 *  * 3) 갈 수 있는 티켓이 없을때 --> visit배열이 모두 true이면 끝, 아니면 pop
 * * LG CNS Code Monster와 비슷하다
 *  */

bool visit[10000]; //방문 여부를 확인하는 배열

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    string start = "ICN";
    int tickSize = tickets.size();
    vector <pair<string, int>> arrive;
    stack<pair<string,int>> stops;
    // stops.push(start);
    // answer.push_back(start);
    int tmpidx, size;
    string tmp;

    while (!stops.empty())
    {
        string current = stops.top();

        // 사용할 수 있는 티켓을 arrive 큐에 집어 넣음
        for (int i = 0; i < tickets.size(); i++)
        {
            // cout << tickets[i][0] <<" "<< current << endl;
            if (!visit[i] && tickets[i][0] == current)
            {
                arrive.push_back(make_pair(tickets[i][1], i));
                cout << " selected spot : " << tickets[i][1] << endl;
            }
        }

        if (arrive.size() > 1)
        {
            size = arrive.size() - 1;
            tmp = arrive.front().first;
            tmpidx = arrive.front().second;
            arrive.pop_back();

            for (int i = 0; i < size; i++)
            {
                if (tmp.compare(arrive.front().first) > 0)
                {
                    tmp = arrive.front().first;
                    tmpidx = arrive.front().second;
                }
                arrive.pop();
            }

            visit[tmpidx] = true;
            answer.push_back(tmp);
            stops.push(tmp);
            // current = tmp;
        }
        else if (arrive.size() == 1)
        {
            tmpidx = arrive.front().second;
            tmp = arrive.front().first;
            visit[tmpidx] = true;
            answer.push_back(tmp);
            stops.push(tmp);
        }
        else
        {
            stops.pop();
            answer.pop_back();
            visit[tmpidx] = false;
        }

        cout << " tmp Idx :: " << tmpidx << endl;
    }

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
