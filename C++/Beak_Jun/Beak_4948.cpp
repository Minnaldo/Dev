#include <algorithm>
#include <cmath>
#include <iostream>

/** 베르트랑 공준 백준_4945 ( https://www.acmicpc.net/problem/4948 )
 *
 */

using namespace std;

int prime[246913];

void table()
{
    for (int i = 2; i <= 246913; i++)
    {
        prime[i] = 1;
    }

    for (int i = 2; i <= 246913; i++)
    {
        if (prime[i] != 0)
        {
            for (int j = i * 2; j <= 246913; j += i) //i만큼 증가하며 0으로 치환, 각 단계마다 i만큼 증가한다 -> i의 배수
                prime[j] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N;

    table();
    while (cin >> N)
    {
        if (N != 0)
        {
            cout << count(&prime[0] + N + 1, &prime[0] + (2 * N) + 1, 1) << endl;
        }
    }
    return 0;
}