#include <algorithm>
#include <iostream>

/** 방 번호 백준_1475 ( https://www.acmicpc.net/problem/1475 )
 *
 */

using namespace std;

int arr[10];

int max(int &a, int &b) { return a > b ? a : b; }

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;

    int size = str.size(), tmp1 = 0, tmp2 = 0;

    for (int i = 0; i < size; i++)
    {
        int tmp = str[i] - '0';
        arr[tmp] = count(str.begin(), str.end(), str[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        if (i != 6 && i != 9)
        {
            tmp2 = max(tmp2, arr[i]);
        }
    }

    tmp1 = arr[9] + arr[6];
    if (tmp1 % 2 == 0)
        tmp1 /= 2;
    else
        tmp1 = (tmp1 / 2) + 1;

    printf("%d\n", max(tmp1, tmp2));

    return 0;
}