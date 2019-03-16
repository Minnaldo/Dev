#include <fstream>
#include <iostream>
#include <vector>

/** 윷놀이 백준_2490 ( https://www.acmicpc.net/problem/2490 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    vector<int> arr(2, 0);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int tmp;
            cin >> tmp;
            arr[tmp + 1]++;
        }

        int ans = (arr[1] * 1) + (arr[2] * 2);
        switch (ans)
        {
        case 4:
            cout << "D" << endl;
            break;
        case 5:
            cout << "C" << endl;
            break;
        case 6:
            cout << "B" << endl;
            break;
        case 7:
            cout << "A" << endl;
            break;
        case 8:
            cout << "E" << endl;
            break;
        }
        arr[1] = 0, arr[2] = 0, ans = 0;
    }
    return 0;
}