#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int T, ans;
    scanf("%d", &T);

    while (T--)
    {
        int N, M, x, y;
        scanf("%d %d %d %d", &N, &M, &x, &y);

        int tmp = abs(N - M), cnt = x;
        int tmpy = x;

        if (N > M)
        {
            cnt += N;
        }
        else if (N < M)
        {
            for (int i = 0; i < M / tmp + 1; i++)
            {
                if( tmpy - tmp < 1 )
                {

                }
                else
                    tmpy -= tmp;

                cnt += N;
            }
        }
        else
        {
            if (x != y)
                ans = -1;
            else
                ans = x;
        }

        while (true)
        {
        }

        printf("%d\n", (cnt * N));
    }

    return 0;
}