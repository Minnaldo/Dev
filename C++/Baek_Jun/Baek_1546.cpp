#include <cmath>
#include <cstdio>
#include <iostream>

/** 평균 백준_1546 ( https://www.acmicpc.net/problem/1546 )
 *  * 소수점 미만의 자릿수를 나타낼 때 ==> cstdio의 %.2f를 써도 괜찮을 듯
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    float answer = 0, max = 0, N;
    scanf("%.2f", &N);
    cin >> N;

    float *arr = new float[(int)N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];

        if (max < arr[i])
            max = arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        answer += (arr[i] / max) * 100;
    }

    printf("%.3f", answer / N);

    return 0;
}