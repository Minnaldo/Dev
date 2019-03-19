#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int n, tmp = 0;
    cin >> n;

    string str = "";
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        tmp += str[i] - '0';
    }

    cout << tmp << endl;

    return 0;
}