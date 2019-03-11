#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N, cnt = 1;
    cin >> N;

    int n = 0;
    if (N / 10 > 0)
    {
        int tmp = (N / 10) + (N % 10);
        n = ((N % 10) * 10) + (tmp % 10);
    }
    else
    {
        int tmp = N + N;
        n = ((N % 10) * 10) + (tmp % 10);
    }

    while (true)
    {
        if (N == n)
        {
            break;
        }

        int tmp = (n / 10) + (n % 10);
        n = ((n % 10) * 10) + (tmp % 10);
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}