#include <iostream>

/** 설탕 배달 백준_2839 ( https://www.acmicpc.net/problem/2839 )
 *  REVIEW
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N, answer = 0, five = -1, three = 0;
    cin >> N;

    if (N % 5 == 0)
    {
        five = N / 5;
    }
    else
    {
        for (int i = N / 5; i >= 0; i--)
        {
            if ((N - (i * 5)) % 3 == 0)
            {
                five = i;
                three = (N - (i * 5)) / 3;
                break;
            }
        }
    }

    answer = five + three;
    cout << answer << endl;

    return 0;
}