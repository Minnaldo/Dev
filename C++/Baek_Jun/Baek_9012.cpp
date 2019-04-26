#include <iostream>
#include <stack>
#include <string>

/** 괄호 백준_9012 ( https://www.acmicpc.net/problem/9012 )
 *  * 스택계산기와 같은 개념으로 하면 된다
 */

using namespace std;

string ans;

bool solution(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            s.push('(');
        else
        {
            if (s.size() > 0)
                s.pop();
            else
                return false;
        }
    }

    return s.empty() ? true : false;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int cnt;
    cin >> cnt;

    while (cnt--)
    {
        string str;
        cin >> str;

        if (solution(str))
        {
            ans = "YES";
        }
        else
        {
            ans = "NO";
        }

        cout << ans << endl;
    }
    return 0;
}