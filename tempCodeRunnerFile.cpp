#include <iostream>

using namespace std;

long long dp[250];

long long solution(int n)
{
    for(int i = 1; i<=n; i++)
    {
        dp[i] = dp[i-1] + (2*dp[i-2]);
    }

    return dp[n];
}

int main(int argc, char const *argv[])
{
    while(!cin.eof())
    {
        int n;
        cin>>n;
        cout<<solution(n)<<endl;
    }
    return 0;
}