#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

/** 인접 리스트 DFS
 *
 *
 */

using namespace std;

bool chk[10001];
vector<pair<int, int>> arr;

void bfs(int start)
{
    int current = start;
    int size = arr.size();
    queue<int> q;
    q.push(current);
}

void dfs(int start)
{
    int size = arr.size();
    int current = start;
    for (int i = 0; i < size; i++)
    {
        if (!chk[i] && arr[i].first == current)
        {
            chk[i] = true;
            cout << arr[i].first << " ";
            current = arr[i].second;
        }
    }
}

int main(int argc, char const *argv[])
{
    sort(arr.begin(), arr.end());
    return 0;
}