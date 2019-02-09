#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

/** 프로그래머스_컬러링북 (https://programmers.co.kr/learn/courses/30/lessons/1829)
 *  ? BFS 응용
 */

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    queue<pair<int, int>> q;
    queue<pair<int, int>> nxt_q;
    q.push(make_pair(0, 0));

    int last_y = 0, last_x = 0, tmpQsize = 0;

    while (true)
    {
        // 이 반복문을 영역의 수만큼 반복해야 한다
        while (!q.empty())
        {
            // 한개의 영역에 대해서  크기를 판단
            int cur_y = q.front().first;
            int cur_x = q.front().second;

            for (int i = 0; i < 4; i++)
            {
                int nxt_y = cur_y + dir[i][0];
                int nxt_x = cur_x + dir[i][1];

                if (nxt_y < m && nxt_y >= 0 && nxt_x < n && nxt_x >= 0)
                {
                    if (picture[cur_y][cur_x] == picture[nxt_y][nxt_x] && picture[nxt_y][nxt_x] != 0) // decision the section that has same color
                    {
                        q.push(make_pair(nxt_y, nxt_x));
                        picture[cur_y][cur_x] = 0; // 더이상 탐색하지 않게 초기화
                    }

                    if (picture[cur_y][cur_x] != picture[nxt_y][nxt_x] && picture[nxt_y][nxt_x] != 0)
                    {
                        nxt_q.push(make_pair(nxt_y, nxt_x));
                    }
                }
            }

            tmpQsize++;
            q.pop();
        }
        number_of_area++;
        max_size_of_one_area = tmpQsize;

        tmpQsize = 0;

        q.push(make_pair(nxt_q.front().first, nxt_q.front().second));
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}

int main(int argc, char const *argv[])
{
    int m = 6, n = 4;
    vector<vector<int>> picture = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};

    vector<int> answer = solution(m, n, picture);

    for (int i = 0; i < 2; i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}