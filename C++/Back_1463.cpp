#include <iostream>

using namespace std;

int solution(int N, int cnt)
{
    solution(N / 3, ++cnt);
    solution(N / 2, ++cnt);
    solution(--N, ++cnt);

    if (N == 1)
    {
        return cnt;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    cout << solution(10, 0) << endl;
    return 0;
}