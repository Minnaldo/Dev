#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);

    string str;
    cin >> str;

    int size = str.size();

    for (int i = 0; i < size; i++)
    {
        int tmp = str[i] - '\0';

        if (65 <= tmp && tmp <= 90)
        {
            cout << str[i] - '@' << " ";
        }
        else if (97 <= tmp && tmp <= 122)
        {
            cout << str[i] - '`' << " ";
        }
    }
    return 0;
}