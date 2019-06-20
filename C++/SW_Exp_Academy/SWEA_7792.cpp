#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/** 반장선거 SWEA_7792 ( https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWsBNHuqMMADFARG&categoryId=AWsBNHuqMMADFARG&categoryType=CODE )
 *
 */

using namespace std;

int n, t;

string solution(vector<pair<string, int>> name)
{
    for (int i = 0; i < n; i++)
    {
        string tmp = name[i].first;
        while (find(tmp.begin(), tmp.end(), ' ') != tmp.end())
            tmp.erase(find(tmp.begin(), tmp.end(), ' '));
        sort(tmp.begin(), tmp.end());

        auto itr = unique(tmp.begin(), tmp.end());
        name[i].second = itr - tmp.begin();
    }

    sort(name.begin(), name.end(), [](pair<string, int> p1, pair<string, int> p2) {
        if (p1.second > p2.second)
            return true;
        else if (p1.second == p2.second)
            if (p1.first.compare(p2.first) < 0)
                return true;
        return false;
    });

    return name[0].first;
}

int main(int argc, char const *argv[])
{
	cin>>t;
    for (int tc = 1; tc <= t; tc++)
    {
        cin>>n;
        vector<pair<string, int>> name;

        string tmp;
        tmp.reserve(20);
        getline(cin, tmp);
        for (int i = 0; i < n; i++)
        {
            getline(cin, tmp);
            if(tmp.back() == ((char)13))
                tmp.pop_back();
            name.push_back(make_pair(tmp, 0));
        }

        cout << "#" << tc << " " << solution(name) << "\n";
    }

    return 0;
}