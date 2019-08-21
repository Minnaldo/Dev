#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++)
    {
        int f, s;
        scanf("%d %d", &f, &s);
        arr.push_back(make_pair(f, s));
    }

    sort(arr.begin(), arr.end(), [](pair<int,int> p1, pair<int,int> p2) -> bool {
        if (p1.second < p2.second)
        {
            return true;
        }
        else if (p1.second == p2.second)
        {
            if (p1.first <= p2.first)
            {
                return true;
            }
        }
        return false;
    });

    int endTime = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].first >= endTime)
        {
            cnt++;
            endTime = arr[i].second;
        }
    }

    printf("%d", cnt);

    return 0;
}