#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }

    sort(arr.begin(), arr.end(), [](pair<int, int> p1, pair<int, int> p2) {
        if (p1.first < p2.first)
        {
            return true;
        }
        else if (p1.first == p2.first)
        {
            if (p1.second < p2.second)
            {
                return true;
            }
        }
        return false;
    });

    for(auto p : arr){
        printf("%d %d\n", p.first, p.second);
    }

    return 0;
}