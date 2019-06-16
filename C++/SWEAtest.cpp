#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int n, t;

string solution(vector<pair<string, int>> &name)
{
    for (int i = 0; i < n; i++)
    {
        string tmp = name[i].first;
        name[i].second = unique(tmp.begin(), tmp.end()) - tmp.begin();
    }

    sort(name.begin(), name.end(), [](pair<string, int> p1, pair<string, int> p2) {
        if (p1.second > p2.second)
            return true;
        else if (p1.second == p2.second)
        {
            if (p1.first.compare(p2.first) < 0)
            {
                return true;
            }
        }
        return false;
    });

    return name[0].first;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d", &n);
        vector<pair<string, int>> name;
        name.reserve(n);

        stringstream ss;

        // cin.ignore();
        ss.ignore();
        for (int i = 0; i < n; i++)
        {
            string tmp;
            // getline(cin, tmp);
            ss.getline()
            name.push_back(make_pair(tmp, 0));
        }

        cout << "#" << tc << " " << solution(name) << "\n";
    }

    return 0;
}