#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, t;

string solution(vector<pair<string, int>> name)
{
    // for (pair<string, int> &aa : name)
    for (int i = 0; i < n; i++)
    {
        string tmp = name[i].first;
        sort(tmp.rbegin(), tmp.rend());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        name[i].second = tmp.back() != ' ' ? tmp.size() : tmp.size() - 1;
    }

    sort(name.begin(), name.end(), [](pair<string, int> p1, pair<string, int> p2) {
        if (p1.second > p2.second)
            return true;
        else if (p1.second == p2.second)
            if (p1.first.compare(p2.first) <= 0)
                return true;
        return false;
    });

    return name[0].first;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<pair<string, int>> name;

        string tmp;
        getline(cin, tmp); //  ??
        for (int i = 0; i < n; i++)
        {
            getline(cin, tmp);
            name.push_back(make_pair(tmp, 0));
        }

        cout << "#" << tc << " " << solution(name) << "\n";
    }

    return 0;
}