#include <iostream>

/** 벌집 백준_2292 ( https://www.acmicpc.net/problem/2292 )
 *  * 규칙을 찾는 문제
 *  * 규칙) 단계가 늘때마다 6의 배수 만큼 늘어난다
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N, answer;
    cin >> N;

    if (N > 1)
    {
        int idx = 1, tmp = 1;
        while (true)
        {
            if (tmp + (6 * idx) >= N)
            {
                answer = idx + 1;
                break;
            }
            tmp += (6 * idx);
            idx++;
        }
    }
    else
    {
        answer = 1;
    }

    cout << answer << endl;

    return 0;
}