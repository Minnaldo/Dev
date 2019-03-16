#include <cmath>
#include <iostream>

using namespace std;

int min(int &a, int &b) { return a < b ? a : b; }

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int a = sqrt(n);
    int b = ceil(a);
    int tmp = 0;
    for (int i = 1; i <= b; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (sqrt(pow(i,2) + pow(j,2)) == a)
            {
                tmp = min(tmp, abs(i-j));
            }
        }
    }

    cout << tmp << endl;
    return 0;
}