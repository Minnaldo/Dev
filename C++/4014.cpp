#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int arr[20][20];
int N, X;

int solution()
{
    int idx = 0, cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int tmp = arr[i][idx];
        auto itr = find(arr[i], arr[i] + N, tmp + 1);
        auto itr2 = find(arr[i], arr[i] + N, tmp - 1);

        if (itr == arr[i] + N && itr2 == arr[i] + N)
        {
            return 1;
        }

        idx++;
    }
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    int T;
    // scanf("%d", &T);
    fs >> T;

    for (int t = 1; t <= T; t++)
    {
        int ans = 0;
        // scanf("%d %d", &N, &X);
        fs >> N >> X;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                // scanf("%d", &arr[i][j]);
                fs >> arr[i][j];

        ans = solution();
        printf("#%d %d\n", t, ans);
    }
    return 0;
}