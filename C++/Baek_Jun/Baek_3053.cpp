#include <cmath>
#include <iostream>

/** 택시 기하학 백준_3053 ( https://www.acmicpc.net/problem/3053 )
 *  * 택시 기하학에서 원의 넓이 2 * R^2 ( R은 반지름 )
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int R;
    cin >> R;

    cout.setf(ios::fixed);
    cout.precision(4);
    cout << M_PI * pow(R, 2) << endl;
    cout << 2 * pow(R, 2) << endl;

    return 0;
}