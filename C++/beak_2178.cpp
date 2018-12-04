#include <iostream>
#include <queue>
#include <algorithm>
#include <sstream>

/** 미로 탐색 백준_2178 (https://www.acmicpc.net/problem/2178)
 *  TODO 입력값을 나눠받아야 함
 */

using namespace std;

bool visit[100][100];
int cnt[100][100];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<pair<int, int>> q;

int solution(string *arr, int n, int m)
{
    // 시작 좌표
    q.push(make_pair(0, 0));
    visit[0][0] = true;
    cnt[0][0] = 1;
    int cur_ypos, cur_xpos;
    while (!q.empty())
    {
        cur_ypos = q.front().first;
        cur_xpos = q.front().second;
        for (int i = 0; i < 4; i++)
        {
            int nxt_ypos = cur_ypos + dir[i][0];
            int nxt_xpos = cur_xpos + dir[i][1];

            if (nxt_ypos >= 0 && nxt_ypos < n && nxt_xpos >= 0 && nxt_xpos < m)
            {
                if (!visit[nxt_ypos][nxt_xpos] && ((arr[nxt_ypos][nxt_xpos] - '0') > 0))
                {
                    q.push(make_pair(nxt_ypos, nxt_xpos));
                    cnt[nxt_ypos][nxt_xpos] = cnt[cur_ypos][cur_xpos] + 1;
                    visit[nxt_ypos][nxt_xpos] = true;
                }
            }
        }
        q.pop();
    }

    return cnt[n-1][m-1];
}

int main(int argc, char const *argv[])
{
    string str = "4 6 101111 101010 101011 111011";
    string str2 = "2 25 1011101110111011101110111 1110111011101110111011101";
    stringstream ss;
    ss.str(str);
    int N, M;
    ss >> N >> M;

    // (0,0) 부터 시작한다
    string *arr = new string[N];
    for (int i = 0; i < N; i++)
    {
        string tmp;
        ss >> tmp;
        arr[i] = tmp;
    }

    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //         if((arr[i][j]-'0') == 1)
    //         {
    //             cout<< "this is integer"<<endl;
    //         }
    //     }
    //     cout << endl;
    // }

    cout << "Answer : " << solution(arr, N, M) << endl;
    delete[] arr;

    return 0;
}