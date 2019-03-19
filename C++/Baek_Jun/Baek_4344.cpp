#include <fstream>
#include <iostream>

/** 평균은 넘겠지 백준_4344 ( https://www.acmicpc.net/problem/4344 )
 *  * C++ 소수점 나타내기 : cout.setf(ios::fixed) 후 cout.precesion(3) ==> 소수점 이하 3째 자리 밑에서 반올림 하여 나타낸다
 *  * 이 문제의 경우 나눗셈 없이 구할 수 있다.
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    fstream fs("input.txt");
    int C;
    fs >> C;

    for (int a = 0; a < C; a++)
    {
        int N, tmp = 0;
        fs >> N;
        int *arr = new int[N];
        for (int i = 0; i < N; i++)
        {
            fs >> arr[i];
            tmp += arr[i];
        }

        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (tmp < arr[i] * N)
                cnt++;
        }

        cout.setf(ios::fixed);
        cout.precision(3);
        cout << (((double)cnt / N) * 100) << "%" << endl;
    }
    return 0;
}