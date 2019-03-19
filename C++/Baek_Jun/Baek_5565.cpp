#include <iostream>

/** 영수증 백준_5565 ( https://www.acmicpc.net/problem/5565 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i < 10; i++)
    {
        int tmp;
        cin >> tmp;
        N -= tmp;
    }
    cout << N << endl;
    return 0;
}