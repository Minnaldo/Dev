#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, ans;
vector<int> arr, lis;

int max(int &a, int &b) { return a > b ? a : b; }

void solution()
{
    int sum;
    for (int i = 0; i < n; i++)
    {
        if (lis.empty() || lis.back() < arr[i])
        {
            lis.push_back(arr[i]);
        }
        else
        {
            sum = 0;
            auto itr = lower_bound(lis.begin(), lis.end(), arr[i]);
            *itr = arr[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    int tmp;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }

    solution();
    cout << ans << endl;

    return 0;
}