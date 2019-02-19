#include <iostream>

using namespace std;

int dp[201];
int cnt;

int solution(int N, int K)
{
    if (K == 0 && N == 0)
    {
        return 1;
    }

    if (N > 0 && K > 0)
    {
        for (int i = 0; i <= N; i++)
        {
            cnt += solution(N - i, K - 1);
        }

        return cnt % 1000000000;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int N, K, cnt = 0;
    cin >> N >> K;

    cout << solution(N, K) << endl;

    return 0;
}