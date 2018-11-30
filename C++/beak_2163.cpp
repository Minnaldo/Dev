#include <iostream>

/** 초콜릿 자르기 백준_2163 (https://www.acmicpc.net/problem/2163)
 *  * 자르는 횟수의 최소값을 구하라
 */

using namespace std;

int dp[301][301];

int min(int a, int b)
{
    return a < b ? a : b;
}

int solution(int n, int m)
{

}

int main(int argc, char const *argv[])
{
    int n, m;
    cin>>n>>m;

    cout<<solution(n,m)<<endl;
    return 0;
}