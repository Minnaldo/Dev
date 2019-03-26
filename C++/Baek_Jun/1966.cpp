#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> arr;

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    int T, ans;
    fs >> T;
    // scanf("%d", &T);

    while (T--)
    {
        int n, m; // n : 문서의 수, m : 궁금한 문서의 현재 큐의 위치
        // scanf("%d %d", &n, &m);
        fs >> n >> m;
        arr.assign(n, make_pair(0, 0));
        for (int i = 0; i < n; i++)
            // scanf("%d", &arr[i]);
            fs >> arr[i].first;

        arr[m].second = 1;

        // main routine
        int flag = true;
        while (flag)
        {
            int chk = arr.front().first;
            auto itr = find_if(arr.begin(), arr.end(), [&chk](pair<int, int> a) { return chk < a.first ? true : false; });
            if (arr.end() != itr)
            {
                arr.push_back(arr.front());
                arr.erase(arr.begin());
            }
            else
            {
                flag = false;
            }
        }

        auto itr = find_if(arr.begin(), arr.end(), [](pair<int, int> a) { a.second == 10 ? true : false; });
        ans = itr - arr.begin();
        printf("%d\n", ans);
    }
    return 0;
}