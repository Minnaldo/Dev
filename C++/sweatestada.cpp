#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

/**
 *  * 재귀함수 형태의 DFS
 *  * DFS에 대해 그리면서 다시 생각해보자
 */

using namespace std;

int t, r, c, answer;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> map(20, vector<int>(20, 0));
vector<vector<bool>> visit(20, vector<bool>(20, false));

int max(int &a, int &b) { return a > b ? a : b; }

int dfs()
{
    int cnt = 0;
    stack<pair<int, int>> s;
    vector<int> special;

    s.push(make_pair(0, 0));
    visit[0][0] = true;
    special.push_back(map[0][0]);
    bool flag = false;

    while (!s.empty())
    {
        int cury = s.top().first;
        int curx = s.top().second;

        for (int i = 0; i < 4; i++)
        {
            int ny = cury + dir[i][0];
            int nx = curx + dir[i][1];

            if (ny >= 0 && ny < r && nx >= 0 && nx < c)
            {
                // find to map ==> 시간 단축 방법 중 하나 일 듯
                if (!visit[ny][nx] && find(special.begin(), special.end(), map[ny][nx]) == special.end())
                {
                    visit[ny][nx] = true;
                    flag = true;
                    s.push(make_pair(ny, nx));
                    special.push_back(map[ny][nx]);
                    break;
                }
            }
        }

        if (!flag)
        {
            // for (auto aa : special)
            //     cout << (char)((aa + 'A' - 1)) << " ";
            // cout << endl;

            cnt = cnt > special.size() ? cnt : special.size();
            s.pop();
            special.pop_back();
        }

        flag = false;
    }

    return cnt;
}

void recur(int y, int x, vector<int> special, vector<vector<bool>> visit, int cnt)
{
    bool flag = false;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];

        // 방문할 수 있는 명물이 있으면, 재귀함수 실행
        if (ny >= 0 && ny < r && nx >= 0 && nx < c)
        {
            if (!visit[ny][nx] && find(special.begin(), special.end(), map[ny][nx]) == special.end())
            {
                flag = true;
                visit[ny][nx] = true;
                special.push_back(map[ny][nx]);

                recur(ny, nx, special, visit, cnt + 1);
                visit[ny][nx] = false;
                special.pop_back();
            }
        }
    }

    // 더이상 길이 없을 때 빠져나와 지나간 수의 명물을 비교하여 answer에 넣는다.
    if (!flag)
        answer = max(answer, cnt);
}

int solution()
{
    vector<int> aa;
    vector<vector<bool>> visit(r, vector<bool>(c, false));
    recur(0, 0, aa, visit, 0);
    return answer;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);

    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d %d", &r, &c);

        string str;
        getline(cin, str);
        for (int i = 0; i < r; i++)
        {
            getline(cin, str);
            for (int j = 0; j < c; j++)
            {
                map[i][j] = str[j] - 'A' + 1; // A : 1 ~ Z : 26
                // cout << map[i][j] << " ";
            }
            // cout << endl;
        }

        printf("#%d %d\n", tc, solution());

        for (int i = 0; i < r; i++)
            fill_n(visit[i].begin(), c, false);
    }
    return 0;
}