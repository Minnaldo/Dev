#include <iostream>
#include <queue>
#include <vector>

/** 프로그래머스_컬러링북 (https://programmers.co.kr/learn/courses/30/lessons/1829)
 *  * Double BFS 이용
 */

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool map[100][100];

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int a = 0; a < m; a++)
    {
        for (int b = 0; b < n; b++)
        {
            if (picture[a][b] != 0 && !map[a][b])
            {
                queue<pair<int, int>> q;
                q.push(make_pair(a, b));
                int section_Size = 1;
                int current_value = picture[a][b];
                while (!q.empty()) // start of BFS
                {
                    // 한개의 영역에 대해서  크기를 판단
                    int cur_y = q.front().first;
                    int cur_x = q.front().second;

                    picture[cur_y][cur_x] = 0;
                    map[cur_y][cur_x] = true;

                    for (int i = 0; i < 4; i++)
                    {
                        int nxt_y = cur_y + dir[i][0];
                        int nxt_x = cur_x + dir[i][1];

                        if (nxt_y < m && nxt_y >= 0 && nxt_x < n && nxt_x >= 0) // 다음 좌표의 범위가 그림 내부 일 때
                        {
                            if (!map[nxt_y][nxt_x] && current_value == picture[nxt_y][nxt_x] && picture[nxt_y][nxt_x] != 0) // decision the section that has same color
                            {
                                picture[nxt_y][nxt_x] = 0; // 더이상 탐색하지 않게 초기화
                                map[nxt_y][nxt_x] = true;
                                section_Size++;
                                q.push(make_pair(nxt_y, nxt_x));
                            }
                        }
                    }
                    q.pop();
                } // end of BFS

                int tmpSectionSize = section_Size;

                if (max_size_of_one_area < tmpSectionSize)
                    max_size_of_one_area = tmpSectionSize;

                number_of_area++;
            }
        }
    }

    vector<int> answer(2, 0);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}

int main(int argc, char const *argv[])
{
    // int m = 6, n = 4;
    // vector<vector<int>> picture = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}}; // 4, 5

    int m = 6, n = 4;
    vector<vector<int>> picture = {{1, 1, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}}; // 2, 6

    vector<int> answer = solution(m, n, picture);

    for (int i = 0; i < 2; i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}