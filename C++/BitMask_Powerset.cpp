#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 *  * C++ 또한 비트마스크 연산이 가능하다
 *  * 비트 연산자 ("&", "^", "|"는 각각의 비트끼리 연산을 해주므로 유용하게 사용이 가능하다.)
 */

int main()
{
    // bit mask test
    string arr[] = {"Apple", "Orange", "Pear"};
    int n = 3;

    for (int i = 0; i < (1 << n); i++)
    {

        string str = "";
        for (int j = 0; j < n; j++)
        {
            if (((1 << j) & i) != 0)
            {
                str += arr[j] + " ";
            }
        }
        cout << str << endl;
    }

    return 0;
}