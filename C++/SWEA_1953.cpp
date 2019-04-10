#include <fstream>
#include <iostream>
#include <queue>

/**
 *  ! canGo & func 함수에서 문제, 방향 설정에서 문제가 생기는 것 같다
 */

using namespace std;

int map[50][50], visit[50][50];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int max(int &a, int &b) { return a > b ? a : b; }

bool func(int direction, int curPipe, int nPipe)
{
    switch (curPipe)
    {
    case 1:
        if (direction == 1)
            return nPipe == 1 ? true : (nPipe == 2 ? true : (nPipe == 5 ? true : (nPipe == 6 ? true : false)));
        else if (direction == 2)
            return nPipe == 1 ? true : (nPipe == 3 ? true : (nPipe == 6 ? true : (nPipe == 7 ? true : false)));
        else if (direction == 3)
            return nPipe == 1 ? true : (nPipe == 2 ? true : (nPipe == 4 ? true : (nPipe == 7 ? true : false)));
        else
            return nPipe == 1 ? true : (nPipe == 3 ? true : (nPipe == 4 ? true : (nPipe == 5 ? true : false)));
    case 2:
        if (direction == 1)
            return nPipe == 1 ? true : (nPipe == 2 ? true : (nPipe == 5 ? true : (nPipe == 6 ? true : false)));
        else if (direction == 3)
            return nPipe == 1 ? true : (nPipe == 2 ? true : (nPipe == 4 ? true : (nPipe == 7 ? true : false)));
    case 3:
        if (direction == 2)
            return nPipe == 1 ? true : (nPipe == 3 ? true : (nPipe == 6 ? true : (nPipe == 7 ? true : false)));
        else if (direction == 4)
            return nPipe == 1 ? true : (nPipe == 3 ? true : (nPipe == 4 ? true : (nPipe == 5 ? true : false)));
    case 4:
        if (direction == 1)
            return nPipe == 1 ? true : (nPipe == 2 ? true : (nPipe == 5 ? true : (nPipe == 6 ? true : false)));
        else if (direction == 2)
            return nPipe == 1 ? true : (nPipe == 3 ? true : (nPipe == 6 ? true : (nPipe == 7 ? true : false)));
    case 5:
        if (direction == 2)
            return nPipe == 1 ? true : (nPipe == 3 ? true : (nPipe == 6 ? true : (nPipe == 7 ? true : false)));
        else if (direction == 3)
            return nPipe == 1 ? true : (nPipe == 2 ? true : (nPipe == 4 ? true : (nPipe == 7 ? true : false)));
    case 6:
        if (direction == 3)
            return nPipe == 1 ? true : (nPipe == 2 ? true : (nPipe == 4 ? true : (nPipe == 7 ? true : false)));
        else if (direction == 4)
            return nPipe == 1 ? true : (nPipe == 3 ? true : (nPipe == 4 ? true : (nPipe == 5 ? true : false)));
    case 7:
        if (direction == 1)
            return nPipe == 1 ? true : (nPipe == 2 ? true : (nPipe == 5 ? true : (nPipe == 6 ? true : false)));
        else if (direction == 4)
            return nPipe == 1 ? true : (nPipe == 3 ? true : (nPipe == 4 ? true : (nPipe == 5 ? true : false)));
    }
}

bool canGo(int cury, int curx, int npy, int npx)
{
    if (cury - npy == 0)
    {
        // 가로 변화
        if (curx - npx < 0)
        {
            //direction : 2
            return func(2, map[cury][curx], map[npy][npx]);
        }
        else
        {
            // direction : 4
            return func(4, map[cury][curx], map[npy][npx]);
        }
    }
    else
    {
        // 세로 변화
        if (cury - npy < 0)
        {
            // direction : 3
            return func(3, map[cury][curx], map[npy][npx]);
        }
        else
        {
            // direction : 1
            return func(1, map[cury][curx], map[npy][npx]);
        }
    }
}

void solution(int y, int x, int n, int m, int l)
{
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    visit[y][x] = 1;

    while (!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;

        for (int i = 0; i < 4; i++)
        {
            int ny = cury + dir[i][0];
            int nx = curx + dir[i][1];

            if (visit[ny][nx] == 0 && (ny >= 0 && ny < n && nx >= 0 && nx < m))
            {
                if (map[ny][nx] != 0 && canGo(cury, curx, ny, nx))
                {
                    q.push(make_pair(ny, nx));
                    visit[ny][nx] = max(visit[cury][curx] + 1, visit[ny][nx]);
                }
            }
        }
        q.pop();
    }
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    int t;
    // scanf("%d", &t);
    fs >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        int ans = 0;
        int n, m, r, c, l;
        // scanf("%d %d", &n, &m);
        // scanf("%d %d", &r, &c);
        fs >> n >> m >> r >> c >> l;

        // int **map = new int *[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                // scanf("%d", &map[i][j]);
                fs >> map[i][j];

        solution(r, c, n, m, l);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << visit[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (visit[i][j] <= l && visit[i][j] > 0)
                {
                    ans++;
                }
                visit[i][j] = 0; // 계산한 배열 초기화
            }

        printf("#%d %d\n", tc, ans);
    }
    return 0;
}