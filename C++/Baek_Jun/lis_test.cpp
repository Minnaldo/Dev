#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr, lis;
int n, ans;

int solution()
{
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = arr[i];
        auto itr = lower_bound(lis.begin(), lis.end(), cur);

        if (itr == lis.end())
        {
            lis.push_back(cur);
            len = lis.size();
        }
        else
        {
            *itr = cur;
            len = itr - lis.begin() + 1;
        }
    }

    return len;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);

    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    cout << solution() << endl;
    return 0;
}