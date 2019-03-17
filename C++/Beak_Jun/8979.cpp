#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d %d", &N, &K);

    int **arr = new int*[N + 1];
    for (int i = 1; i <= N; i++)
    {
        arr[i] = new int[4];
        for(int j = 1; j<=4; j++)
        {
            cin>>arr[i][j];
        }
    }
    return 0;
}