#include <fstream>
#include <iostream>
#include <sstream>

/** 다리 놓기 백준_1010 (https://www.acmicpc.net/problem/1010)
 *  * 참조 (http://lmcoa15.tistory.com/8)
 *  * 참조 2 (http://degurii.tistory.com/29)
 *  ? 얘도 방사형으로 나올까?
 */

using namespace std;

int dp[31];

long long solution(int n, int m)
{
    if (n == m)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
        }

        long long answer = dp[1];
        for (int i = 2; i <= n; i++)
        {
            answer *= dp[i];
        }
        return answer;
    }
}

int main(int argc, char const *argv[])
{
    // string str = "3 2 2 1 5 13 29";  // 1, 5, 67863915
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
            cout << solution(n, m) << endl;
        }
    }
    return 0;
}