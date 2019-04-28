#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, ans;
    cin >> a >> b;

    int tmp = abs(a - b);

    if (tmp == 1)
    {
        cout << ((a - b) < 0 ? "B" : "A") << endl;
    }
    else if(tmp == 2)
    {
        cout << ((a - b) < 0 ? "A" : "B") << endl;
    }

    return 0;
}