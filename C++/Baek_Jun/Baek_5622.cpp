#include <iostream>
#include <string>

/** 다이얼 백준_5622 ( https://www.acmicpc.net/problem/5622 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    int size = str.size(), answer = 0;

    int arr[29] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

    for (int i = 0; i < size; i++)
    {
        int tmp = str[i] - 'A';
        answer += (arr[tmp] + 1);
    }

    cout << answer << endl;
    return 0;
}