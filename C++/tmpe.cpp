#include <iostream>
#include <cmath>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N, sum, M, tmp;
    cin >> N;

    int *arr = new int[N];

    cin >> tmp;
    arr[0] = tmp;
    M = arr[0];
    for (int i = 1; i < N; i++)
    {
        cin >> tmp;
        arr[i] = tmp;

        if (M > arr[i])
        {
            M = M;
        }
        else if (M < arr[i])
        {
            M = arr[i];
        }
    }

    cout << M << endl;

    for (int i = 0; i < N; i++)
    {
        arr[i] = (arr[i] / M) * 100;
        sum += arr[i];
    }

    pow(2,2);

    cout << (sum / N) << endl;

    return 0;
}