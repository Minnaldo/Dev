#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool chk1[101], chk2[101];

int solution(int n1, vector<vector<int>> g1, int n2, vector<vector<int>> g2)
{
    int answer = 0;

    stack<pair<int, int>> s1;
    stack<pair<int, int>> s2;

    for (int i = 0; i < g1.size(); i++)
    {
        if (g1[i][0] == 1)
        {
            s1.push(make_pair(i, 0)); // 시작좌표 삽입
            s1.push(make_pair(i, 1));
            chk1[i] = true;
        }
    }

    for (int i = 0; i < g2.size(); i++)
    {
        if (g2[i][0] == 1)
        {
            s2.push(make_pair(i, 0)); // 시작좌표 삽입
            s2.push(make_pair(i, 1));
            chk2[i] = true;
        }
    }

    int Count1 = 0;
    int tmpCnt1 = 0;
    while (!s1.empty())
    {
        int cur_x = s1.top().first;
        int cur_y = s1.top().second;

        for (int i = 0; i < g1.size(); i++)
        {
            if (!chk1[i] && g1[cur_y][cur_x] == g1[i][0])
            {
                s1.push(make_pair(i, 1));
                Count1++;
            }
        }

        s1.pop();

        if(tmpCnt1 < Count1)
        {
            tmpCnt1 = Count1;
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    int n1 = 8;
    vector<vector<int>> g1 = {{3, 1}, {5, 7}, {8, 7}, {2, 3}, {3, 6}, {1, 5}, {4, 3}};
    int n2 = 9;
    vector<vector<int>> g2 = {{1, 5}, {5, 6}, {3, 7}, {3, 1}, {7, 4}, {7, 2}, {9, 8}, {5, 9}};

    cout << solution(n1, g1, n2, g2) << endl;
    return 0;
}