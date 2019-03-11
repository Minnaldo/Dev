#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    string str = "";
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        if (i % 10 == 0 && i > 1)
        {
            cout << endl;
        }
        cout << str[i];
    }
    return 0;
}