#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

/** 미로 탐색 백준_2178 (https://www.acmicpc.net/problem/2178)
 *  TODO 입력값을 나눠받아야 함
 */


using namespace std;

bool visit[100][100];
int cnt[100][100], dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<pair<int, int>> q;

int min(int a, int b)
{
    return a < b ? a : b;
}

int solution(int **arr, int n, int m)
{
    int cur_xpos = q.front().second;
    int cur_ypos = q.front().first;

    while (!q.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int nxt_ypos = cur_ypos + dir[i][0];
            int nxt_xpos = cur_xpos + dir[i][1];

            if (nxt_ypos >= 0 && nxt_ypos < n && nxt_xpos >= 0 && nxt_xpos < m)
            {
                if (!visit[nxt_ypos][nxt_xpos] && (arr[nxt_ypos][nxt_xpos] == 1))
                {
                    q.push(make_pair(nxt_ypos, nxt_xpos));
                    visit[nxt_ypos][nxt_xpos] = true;

                    if (cnt[cur_ypos][cur_xpos] > 1)
                    {
                        cnt[nxt_ypos][nxt_xpos] = min(cnt[nxt_ypos][nxt_xpos], cnt[cur_ypos][cur_xpos] + 1);
                    }
                }
            }
        }
        q.pop();
    }

    return cnt[n][m];
}

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);

    int **arr = new int *[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[M];
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    q.push(make_pair(0, 0));
    visit[0][0] = true;
    cnt[0][0] = 1;

    printf("%d\n", solution(arr, N, M));
    return 0;
}