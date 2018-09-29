#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string line;
    line = {"11", "128", "15", "111", "59", "31", "70", "102", "50", "172", "88", "56", "40", "41", "12"};
    stringstream ss(line);

    for (int distance; !(ss >> distance).fail();)
    {
    }
    cout << endl;
    return 0;
}
