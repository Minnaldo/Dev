#include <iostream>

using namespace std;

int dp[301][301];

int solution(int** arr, int i, int j, int x, int y)
{
    dp[i][j] = arr[i][j];


}

int main(int argc, char const *argv[])
{

    int N, M;

    cin>>N>>M;

    int** arr = new int* [N+1];
    for(int i = 1; i<=N; i++)
    {
        arr[i] = new int [M+1];
        for(int j = 1; j<=M; j++)
        {
            int tmp;
            cin>>tmp;
            arr[i][j] = tmp;
        }
    }

    int K;
    cin>>K;
    for(int i = 0; i<K; i++)
    {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        cout<<solution(arr, a, b, c, d)<<endl;
    }

    return 0;
}