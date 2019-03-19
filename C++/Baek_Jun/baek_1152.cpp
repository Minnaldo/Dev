#include <iostream>
#include <string>

/** 단어의 개수 백준_1152 ( https://www.acmicpc.net/problem/1152 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);
    int size = str.size();
    int cnt = 0;
    for (int i = 0; i < size; i++)
    {
        int idx = i + 1;
        if (str[i] != ' ')
        {
            while (str[idx] != ' ' && idx < size)
            {
                idx++;
            }
            cnt++;
            i = idx;
        }
    }

    cout << cnt << endl;
    return 0;
}