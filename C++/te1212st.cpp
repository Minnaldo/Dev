#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{

    string answer = "";

    map<string, int> m;
    pair<map<string, int>::iterator, bool> ret;

    for (auto ss : participant)
    {
        ret = m.insert(make_pair(ss, 1));
        if (!ret.second)
            m[ss]++;
    }

    for (auto ss : completion)
        m[ss]--;

    for (auto aa : m)
        if (aa.second == 1)
            answer = aa.first;

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<string> aa = {"leo", "kiki", " eden"};
    vector<string> bb = {"kiki", "eden"};

    cout << solution(aa, bb) << endl;

    return 0;
}