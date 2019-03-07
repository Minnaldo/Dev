#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    while (!cin.eof())
    {
        string str = "";
        getline(cin, str);
        cout << str << endl;
    }
    return 0;
}