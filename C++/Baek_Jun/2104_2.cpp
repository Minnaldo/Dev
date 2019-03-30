#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

long long arr[100000], psum[100000];

long long min(long long &a, long long &b) { return a < b ? a : b; }
long long max(long long &a, long long &b) { return a > b ? a : b; }

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    long long n, ans = 0;
    // scanf("%lld", &n);
    fs >> n;
    fs >> arr[0];
    psum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        // scanf("%lld", &arr[i]);
        fs >> arr[i];
        psum[i] = psum[i - 1] + 1;
    }

    for (int i = 0; i < n; i++)
    {
        auto itr = lower_bound(arr, arr + i - 1, arr[i]);
        auto itr2 = upper_bound(arr + i + 1, arr + n, arr[i]);
        auto itr3 = lower_bound(arr + i + 1, arr + n, arr[i]);
        auto itr4 = upper_bound(arr, arr + i - 1, arr[i]);
        long long tmpsum = psum[(itr2 - &arr[0])] - psum[(itr - &arr[0])], tmpsum2 = psum[(itr4 - &arr[0])] - psum[(itr3 - &arr[0])];
        long long mul = arr[i];
        ans = max(ans, max(tmpsum * mul, tmpsum2 * mul));
    }

    printf("%lld\n", ans);
    return 0;
}