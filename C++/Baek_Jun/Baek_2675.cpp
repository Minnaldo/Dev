#include <iostream>
#include <string>

/** 문자열 반복 백준_2675 ( https://www.acmicpc.net/problem/2675 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    for (int a = 0; a < T; a++)
    {
        int R;
        string str;
        cin >> R >> str;
        int size = str.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < R; j++)
            {
                cout<<str[i];
            }
        }
        cout<<endl;
    }
    return 0;
}