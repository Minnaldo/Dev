#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool chk[10001], chk2[10001];
// int arr[2][10001];
vector<pair<int, int>> arr;

// void bfs(int start, int N)
// {
//     int current = start;
//     queue<int> q;
//     q.push(current);
//     chk2[current] = true;
//     printf("%d ", current);

//     while (!q.empty())
//     {
//         current = q.front();
//         for (int i = 1; i <= N; i++)
//         {
//             if (!chk2[i] && arr[current][i] == 1)
//             {
//                 printf("%d ", i);
//                 q.push(i);
//                 chk2[i] = true;
//             }
//         }
//         q.pop();
//     }
// }

void dfs(int start, int N)
{
    int current = start;
    chk[current] = true;
    // printf("%d ", current);
    for (int i = 0; i < N; i++)
    {
        if (!chk[i] && arr[i].first == current)
        {
            chk[i] = true;
            printf("%d ", arr[i].first);
            current = arr[i].second;
        }
    }
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    int N, M, start;
    // scanf("%d %d %d", &N, &M, &start);
    fs >> N >> M >> start;

    int y, x;
    for (int i = 0; i < M; i++)
    {
        // scanf("%d %d", &y, &x);
        fs >> y >> x;
        arr.push_back(make_pair(y, x));
    }

    sort(arr.begin(), arr.end());

    dfs(start, N);
    printf("\n");
    // bfs(start, N);
    // printf("\n");
    return 0;
}