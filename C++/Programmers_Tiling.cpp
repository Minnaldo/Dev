#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

/**
 * *
 */

int dp[100];

//2* width 크기의 사각형을 채우는 방법의 수 리턴
int tiling(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    int &ret = dp[n];

    if (ret != -1)
    {
        return ret;
    }
    return ret = tiling(n - 2) + tiling(n - 1);
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cout<<tiling(n)<<endl;
    return 0;
}