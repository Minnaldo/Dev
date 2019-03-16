#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/** 농구 경기 백준_1159 ( https://www.acmicpc.net/problem/1159 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<string> arr(N);
    vector<int> tmp(26, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        tmp[(arr[i][0] - 'a')]++;
    }

    if (find_if(tmp.begin(), tmp.end(), [](int &a) { return a >= 5 ? true : false; }) == tmp.end())
    {
        cout << "PREDAJA" << endl;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (5 <= tmp[i])
            {
                string str;
                str = 'a' + i;
                cout << str;
            }
        }
        cout << endl;
    }

    return 0;
}