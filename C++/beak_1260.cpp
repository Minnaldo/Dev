#include <iostream>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

bool visit[10000];

int DFS(int n, int **arr)
{
    for (int i = 0; i < n; i++)
    {
        if(!visit[i] && (arr[i][0] == n))
        {
            cout<<n<<" ";
            DFS(arr[i][1], arr);
        }
    }
    return 0;
}

int BFS(int n, int **arr)
{
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);

    stringstream ss;
    string str = "4 5 1 1 2 1 3 1 4 2 4 3 4";
    ss.str(str);

    int N, M, V;
    ss >> N >> M >> V;

    int **arr = new int *[M];
    for (int i = 0; i < M; i++)
    {
        arr[i] = new int[2];
        for (int j = 0; j < 2; j++)
        {
            int tmp;
            ss >> tmp;
            arr[i][j] = tmp;
        }
    }

    DFS(V, arr);
    cout<<endl;
    // BFS(V, arr);

    return 0;
}