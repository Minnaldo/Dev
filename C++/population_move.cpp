#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

/** 인구이동 (https://www.acmicpc.net/problem/16234)
 * * BFS이용해 탐색, 더이상 조건에 맞는 셀이 없을경우 카운트 1 증가
 * * 인구수를 P 라 할때,  L <= p[1] - p[2] <= R 이면 국경선 오픈
 * * 연합인 각 나라의 인구수는 (연합의인구수)/(연합인 나라 수), 소수점 버림
 * * 하루가 지난후(인구이동이 완료되면) 모든 국경선 폐쇄
 */

bool visit[50][50];
int min, max, count;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<int> pop;

int BFS(vector<int> region)
{
    queue<pair<int, int>> cur_pos;
    cur_pos.push(make_pair(0, 0));
    pop.push(region[cur_pos.front().first][cur_pos.front().second]);
    visit[cur_pos.front().first][cur_pos.front().second] = true;
    int count = 0;

    while (!cur_pos.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int nxt_y = cur_pos.front().first + dir[i][0];
            int nxt_x = cur_pos.front().second + dir[i][1];
            //다음 위치기 맵 안에 있는가?
            if (nxt_y >= 0 && nxt_y < N && nxt_x >= 0 && nxt_x < N)
            {
                int tmp = region[cur_y][cur_x] - region[nxt_y][nxt_x];
                //인구수 차이가 L이상, R이하인가?
                if (!visit[nxt_y][nxt_x] && ((tmp >= L && tmp <= R) || (tmp >= -L && -tmp <= R)))
                {
                    cur_pos.push(make_pair(nxt_y, nxt_x));
                    pop.push(region[nxt_y][nxt_x]);
                    visit[nxt_y][nxt_x] = true;
                }
                else
                {
                    int country_size = pop.size();
                    int popul = 0;
                    for (int s = 0; s < country_size; s++)
                    {
                        popul += pop.front();
                        pop.pop();
                    }
                    popul /= country_size;
                    cur_pos.pop();
                    count++;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int N, L, R;
    scanf("%d %d %d", &N, &L, &R);
    vector<vector<int>> arr(N, vector<int>(N));
    min = L;
    mzx = R;
    // int **arr = new int *[N];
    for (int i = 0; i < N; i++)
    {
        // arr[i] = new int [N];
        for (int j = 0; j < N; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            arr[i][j] = tmp;
        }
    }

    BFS(arr);
}