#include <fstream>
#include <iostream>
#include <sstream>

/** 다리 놓기 백준_1010 (https://www.acmicpc.net/problem/1010)
 *  * 참조 (http://lmcoa15.tistory.com/8)
 *  * 참조 2 (http://degurii.tistory.com/29)
 */

using namespace std;

int dp[31][2];

int solution(int n, int m)
{
    for (int i = 2; i <= n; i++)
    {
    }

    return dp[n][m];
}

int main(int argc, char const *argv[])
{
    // string str = "3 2 2 1 5 13 29";
    // stringstream ss;
    // ss.str(str);

    ifstream fs("input.txt");
    int T;
    // ss >> T;

    while (fs >> T)
    {
        for (int i = 0; i < T; i++)
        {
            int n, m;
            fs >> n >> m;
            dp[1] = m - (n - 1);
            cout << solution(n, m) << endl;
        }
    }
    return 0;
}