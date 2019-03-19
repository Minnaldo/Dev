#include <iostream>
#include <string>

/** 상수 백준_2908 ( https://www.acmicpc.net/problem/2908 )
 *  * 같은경우는 주어지지 않는다.
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    string str, str1, tmp, tmp1;
    cin >> str >> str1;

    tmp.assign(str.rbegin(), str.rend());
    tmp1.assign(str1.rbegin(), str1.rend());

    int val = tmp.compare(tmp1);

    if (val > 0)
        cout << tmp << endl;
    else if (val < 0)
        cout << tmp1 << endl;
    return 0;
}