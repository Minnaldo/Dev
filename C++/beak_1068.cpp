#include <fstream>
#include <iostream>

/**
 *  * 2차원 배열로 구현해볼까?
 */

using namespace std;

int cnt, lim;

int solution(int *arr, int idx)
{
    if (idx >= lim)
    {
        return 0;
    }
    else
    {
        arr[idx] = -2;
    }

    solution(arr, (idx * 2) + 1);
    solution(arr, (idx * 2) + 2);
}

int main(int argc, char const *argv[])
{
    ifstream fs("input.txt");
    int del;
    cin >> lim;

    int *arr = new int[lim];

    for (int i = 0; i < lim; i++)
    {
        cin >> arr[i];
    }
    cin >> del;
    solution(arr, del);

    for (int i = lim; i > 0; i--)
    {
        if (arr[i] != -2)
        {
            cnt++;
        }
    }
    return 0;
}