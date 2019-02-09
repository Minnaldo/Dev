#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    serachElement(m, n, picture); // 원소 종류를 element 전역 벡터에 저장

    queue<pair<int, int>> q;
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
                    if (picture[cur_y][cur_x] == picture[nxt_y][nxt_x] && picture[cur_y][cur_x] != 0) // decision the section that has same color
                    {
                        q.push(make_pair(nxt_y, nxt_x));
                        picture[cur_y][cur_x] = 0; // 더이상 탐색하지 않게 초기화
                    }
                }
            }

            if (tmpQsize < q.size()) // section size update
            {
                tmpQsize = q.size();
            }
            last_y = q.back().first;
            last_x = q.back().second;

            if (q.size() <= 1)
            {
                for (int i = 0; i < 4; i++)
                {
                    int nxt_last_y = last_y + dir[i][0];
                    int nxt_last_x = last_x + dir[i][1];

                    if (nxt_last_y >= 0 && nxt_last_y < m && nxt_last_x >= 0 && nxt_last_x < n)
                    {

                    }
                }
            }

            q.pop();
        }
        number_of_area++;

        q.push(make_pair(last_y, last_x));
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}

int main(int argc, char const *argv[])
{
    return 0;
}