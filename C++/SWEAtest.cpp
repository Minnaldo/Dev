#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d", &n);
        vector<pair<string, int>> name;

        string tmp;
        getline(cin, tmp); //  ?? cin은 공백 또는 개행문자가 나오면 입력 받는것을 중지하는데 이 때, 공백 또는 개행문자를 버퍼에 그대로 나두기 때문에 해주어야 함
        for (int i = 0; i < n; i++)
        {
            getline(cin, tmp);

            if (tmp.back() == ' ')
                tmp.pop_back();

            name.push_back(make_pair(tmp, 0));
        }

        cout << "#" << tc << " " << solution(name) << "\n";
    }

    return 0;
}