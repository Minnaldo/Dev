#include <iostream>
#include <string>

/** 크로아티아 알파벳 백준_2941 ( https://www.acmicpc.net/problem/2941 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    int size = str.size(), answer = 0;

    for (int i = 0; i < size; i++)
    {
        if (str[i] == 's' || str[i] == 'z')
        {
            if (str[i + 1] == '=')
                i += 1;
        }
        else if (str[i] == 'd')
        {
            if (str[i + 1] == 'z' && str[i + 2] == '=')
                i += 2;
            else if (str[i + 1] == '-')
                i += 1;
        }
        else if (str[i] == 'c')
        {
            if (str[i + 1] == '=' || str[i + 1] == '-')
                i += 1;
        }
        else if (str[i] == 'n' || str[i] == 'l')
        {
            if (str[i + 1] == 'j')
                i += 1;
        }

        answer++;
    }

    cout<< answer << endl;
    return 0;
}