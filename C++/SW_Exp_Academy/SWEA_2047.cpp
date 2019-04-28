#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        str[i] = toupper(str[i]);
    }
    cout << str << endl;
    return 0;
}