#include <iostream>

/** 아스키 코드 백준_11654 ( https://www.acmicpc.net/problem/11654 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    char a;
    cin >> a;

    cout << a - '\0' << endl;
    return 0;
}