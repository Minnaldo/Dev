#include <iostream>

/** 평균 점수 백준_10039 ( https://www.acmicpc.net/problem/10039 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int answer=0, N;

    for (int i = 0; i < 5; i++)
    {
        cin >> N;
        if (N >= 40)
            answer += N;
        else
            answer += 40;
    }

    cout << answer / 5 << endl;

    return 0;
}