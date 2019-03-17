#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> strtok(string str, char delemeter = ' ')
{
    vector<string> result;

    auto itr = str.begin();
    int idx = 0;
    int cnt = 1;
    while (itr != str.end())
    {
        if (*itr == delemeter || *itr == str.back())
        {
            string tmpstr;
            int current = (*itr == str.back()) ? str.size() : (itr - str.begin());
            tmpstr.assign(str, idx, current - idx);
            result.push_back(tmpstr);
            cout << cnt << " : " << result.back() << endl;
            idx = current + 1;
            cnt++;
        }
        itr++;
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<string> ans;
    ans = strtok("abc bcd 178");

    int size = ans.size();
    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}