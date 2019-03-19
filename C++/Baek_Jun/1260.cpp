#include <fstream>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int chk[1001];
int arr[1001][1001], print[10001], index;

void bfs(int start, int N)
{
    queue<int> q;
    q.push(start);
    chk[start] = 1;
    int idx = 1;
    while (!q.empty())
    {
        int current = q.front();
        print[idx] = current;
        idx++;
        for (int i = 1; i <= N; i++)
        {
            if (chk[i] == 0 && arr[current][i] != 0)
            {
                q.push(i);
                chk[i] = 1;
            }
        }
        q.pop();
    }
    index = idx;
}

void dfs(int start, int N)
{
    stack<int> s;
    s.push(start);
    chk[start] = true;
    int current = s.top();
    int idx = 1;
    while (!s.empty())
    {
        print[idx] = current;
        idx++;
        for (int i = 1; i <= N; i++)
        {
            if (chk[i] == 0 && arr[current][i] == 1)
            {
                s.push(i);
                chk[i] = 1;
                current = i;
                break;
            }
        }
        s.pop();
    }
    index = idx - 1;
}

void printarr()
{
    for (int i = 1; i <= index; i++)
    {
        if (i != index)
            printf("%d ", print[i]);
        else
            printf("%d", print[i]);
    }
    printf("\n");
    index = 0;
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    ios::sync_with_stdio(false);
    int N, M, start;
    fs >> N >> M >> start;

    for (int i = 0; i < M; i++)
    {
        int y, x;
        fs >> y >> x;
        arr[y][x] = 1;
        arr[x][y] = 1;
    }

    dfs(start, N);
    printarr();
    fill(chk, chk + M, 0);
    bfs(start, N);
    printarr();
    return 0;
}