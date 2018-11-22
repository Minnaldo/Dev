#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * * 1부터 시작해서 n이되게 만든다
 * * n/3 -> n*3, n/2 -> n*2, n-1 -> n+1
 */

int N;

int solution(int n, int cnt)
{

    if (n == N)
    {
        return cnt;
    }
    else if (n > N)
    {
        return 0;
    }
    else if (n <N)
    {
        solution(n * 3, ++cnt);
        solution(n * 2, ++cnt);
        solution(++n, ++cnt);
    }
}

int main(int argc, char const *argv[])
{
    N = 10;
    cout << solution(1, 0) << endl;
    return 0;
}