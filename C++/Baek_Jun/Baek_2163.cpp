#include <iostream>

/** 초콜릿 자르기 백준_2163 (https://www.acmicpc.net/problem/2163)
 *  * 자르는 횟수의 최소값을 구하라
 *  * 규칙을 찾으면 DP를 적용하지 않아도 수식하나로 끝이 난다.
 *  * 규칙의 수식화 ==> n*(m-1) + (n-1)
 */

using namespace std;

int solution(int n, int m)
{
    return (m * (n - 1)) + (m - 1);
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    cout << solution(n, m) << endl;
    return 0;
}