#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, ans = 0;
    cin >> n;

    for (int i = 3; i >= 0; i--)
    {
        ans += n / pow(10, i);
        n = n % (int)(pow(10, i));
    }

    cout << ans << endl;

    return 0;
}