#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, strsize, ans;
vector<string> arr;
vector<string> tmp;

bool solution(int k)
{
    for (int j = 0; j < n; j++)
    {
        string tmpstr;
        for (int i = k; i >= 0; k--)
        {
            tmpstr += arr[j][strsize - 1 - k];
        }

        if (find(tmp.begin(), tmp.end(), tmpstr) == tmp.end())
        {
            tmp.push_back(tmpstr);
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        arr.push_back(str);
    }

    strsize = arr[0].size();
    ans = 1000;
    for (int i = 0; i <= strsize; i++)
    {
        if (solution(i))
        {
            ans = min(ans, i);
        }
    }

    printf("%d\n", ans);

    return 0;
}