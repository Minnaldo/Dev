#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int N, M;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool chk[1001][1001];

int max(int &a, int &b) { return a > b ? a : b; }

// TODO how to search for square in 2-dimetion array
int solution(int **arr, int y, int x, int mul)
{
    int tmp = 0;
    for (int i = y; i <= mul; i++)
    {
        for (int j = x; j <= mul; j++)
        {
            if (arr[i][j] == 1)
                if (i > 0 && j > 0 && i <= N && j <= M)
                    tmp++;
        }
    }

    if (tmp % mul == 0)
    {
        return tmp;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    ios::sync_with_stdio(false);
    cin.tie();

    fs >> N >> M;

    string str = "";

    int **arr = new int *[N + 1];
    for (int i = 1; i <= N; i++)
    {
        arr[i] = new int[M + 1];
        fs >> str;
        for (int j = 0; j < M; j++)
        {
            arr[i][j + 1] = str[j] - '0';
        }
    }

    int answer = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            for (int k = 1; k <= N || k <= M; k++)
                answer = max(answer, solution(arr, i, j, k));
        }
    }

    cout << answer << endl;
    return 0;
}