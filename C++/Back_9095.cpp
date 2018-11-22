#include <iostream>

using namespace std;

/** 1,2,3 더하기 백준온라인저지_9095번 (https://www.acmicpc.net/problem/9095)
 * * DP Algorithm Problem, Use Recursive Function
 * * 목표 수 n에서 빼는 방법으로 표현 함
 * ? Bottom-Up 방식의 dp로 풀려면??
 * TODO : bottom Up 방식으로 풀어보자
 */

int cnt;

int solution(int n)
{

    if (n == 0)
    {
        cnt++;
        return 0;
    }
    if (n > 0)
    {
        solution(n - 1);
        solution(n - 2);
        solution(n - 3);
    }
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        cnt = 0;
        solution(n);
        cout << cnt << endl;
    }
    return 0;
}