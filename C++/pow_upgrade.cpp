#include <chrono>
#include <cmath>
#include <iostream>

using namespace std;

long long dp[1001];

long long solution(int base, int exp)
{
    if (exp == 1)
        return dp[1];

    if (exp % 2 == 1)
    {
        dp[exp] = solution(base, exp / 2) * solution(base, exp / 2) * dp[1];
    }
    else
    {
        dp[exp] = solution(base, exp / 2) * solution(base, exp / 2);
    }

    return dp[exp];
}

long long custom(int base, int exp)
{
    long long ans = 1;
    for (int i = 1; i <= exp; i++)
    {
        ans *= base;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int base = 3, exp = 20;

    dp[0] = 1;
    dp[1] = base;

    auto start = chrono::system_clock::now();
    cout << "Solution ::" << solution(base, exp) << endl;
    auto end = chrono::system_clock::now();

    cout << (float)(end - start).count() / CLOCKS_PER_SEC << endl;

    start = chrono::system_clock::now();
    cout << "POW :: " << pow(base, exp) << endl;
    end = chrono::system_clock::now();
    cout << (float)(end - start).count() / CLOCKS_PER_SEC << endl;

    start = chrono::system_clock::now();
    cout << "Custom :: " << custom(base, exp) << endl;
    end = chrono::system_clock::now();
    cout << (float)(end - start).count() / CLOCKS_PER_SEC << endl;
    return 0;
}