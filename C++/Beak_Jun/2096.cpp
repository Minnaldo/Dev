#include <fstream>
#include <iostream>

using namespace std;

int **arr;

int max(int &a, int &b) { return a > b ? a : b; }
int min(int &a, int &b) { return a < b ? a : b; }

int solution(int n)
{
    int min_ans = 0, max_ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                min_ans += min(arr[i][j] + arr[i + 1][j], arr[i][j] + arr[i + 1][j + 1]);
                max_ans += max(arr[i][j] + arr[i + 1][j], arr[i][j] + arr[i + 1][j + 1]);
            }
            if (j == 1)
            {
                min_ans += min(arr[i][j] + arr[i + 1][j - 1], min(arr[i][j] + arr[i + 1][j], arr[i][j] + arr[i + 1][j + 1]));
                max_ans += max(arr[i][j] + arr[i + 1][j - 1], max(arr[i][j] + arr[i + 1][j], arr[i][j] + arr[i + 1][j + 1]));
            }
            if (j == 2)
            {
                min_ans += min(arr[i][j] + arr[i + 1][j], arr[i][j] + arr[i + 1][j - 1]);
                max_ans += max(arr[i][j] + arr[i + 1][j], arr[i][j] + arr[i + 1][j - 1]);
            }
        }
    }

    cout << max_ans << " " << min_ans << endl;
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    ios::sync_with_stdio(false);
    int N;
    fs >> N;

    arr = new int *[N + 1];

    for (int i = 1; i <= N; i++)
    {
        arr[i] = new int[3];
        for (int j = 1; j <= 3; j++)
        {
            fs >> arr[i][j];
        }
    }

    solution(N);

    return 0;
}