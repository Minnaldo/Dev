#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

/**
 * * 시간초과
 */

vector <long long> arr;

long long func(long long n)
{
    arr.push_back(1);
    arr.push_back(3);

    float cnt = 2;

    while (arr.size() <= n)
    {
        int tmpidx = arr.size() - 1;

        for (int j = 0; j < tmpidx; j++)
        {
            arr.push_back(arr[tmpidx] + arr[j]);
        }

        arr.push_back(pow(3, cnt));

        cnt++;
    }

    return arr[n - 1];
}

long long solution(long long n)
{
    long long answer = func(n);
    return answer;
}

int main(int argc, char const *argv[])
{
    long long n = 11;
    cout << solution(n) << endl;

    return 0;
}