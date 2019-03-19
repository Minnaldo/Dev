#include <iostream>

/** 음계 백준_2920 ( https://www.acmicpc.net/problem/2920 )
 *  * 특이점 : 그저 차례대로만 나오면 끝, 특별한 반례가 없다
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int arr[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < 8; i++)
    {
        if (arr[i] - arr[i - 1] != 1 && arr[i] - arr[i - 1] != -1)
        {
            cout << "mixed" << endl;
            return 0;
        }
    }

    if (arr[1] - arr[0] == 1)
        cout << "ascending" << endl;
    else
        cout << "descending" << endl;
    return 0;
}