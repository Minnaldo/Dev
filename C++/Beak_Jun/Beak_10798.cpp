#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/** 세로읽기 백준_10798 ( https://www.acmicpc.net/problem/10798 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    vector<string> arr(5, "");
    int size = 0;
    for (int i = 0; i < 5; i++)
    {
        fs >> arr[i];
        if (size < arr[i].size())
            size = arr[i].size();
    }
    int idx = 0;
    while (idx < size)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[j][idx] != '\0')
                cout << arr[j][idx];
        }
        idx++;
    }

    return 0;
}