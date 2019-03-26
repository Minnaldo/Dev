#include <deque>
#include <fstream>
#include <iostream>

/** 덱 백준_10866 ( https://www.acmicpc.net/problem/10866 )
 *
 */

using namespace std;

deque<int> dq;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie();
    int n, aa, tmp;
    string str;
    cin >> n;
    while (n--)
    {
        cin >> str;
        if (str == "push_front")
        {
            cin >> tmp;
            dq.push_front(tmp);
        }
        else if (str == "push_back")
        {
            cin >> tmp;
            dq.push_back(tmp);
        }
        else if (str == "pop_front")
        {
            if (dq.empty())
                printf("-1\n");
            else
            {
                aa = dq.front();
                printf("%d\n", aa);
                dq.erase(dq.begin());
            }
        }
        else if (str == "pop_back")
        {
            if (dq.empty())
                printf("-1\n");
            else
            {
                aa = dq.back();
                printf("%d\n", aa);
                dq.erase(dq.end());
            }
        }
        else if (str == "size")
        {
            if (dq.empty())
                printf("%d\n", 0);
            else
            {
                aa = dq.size();
                printf("%d\n", aa);
            }
        }
        else if (str == "empty")
        {
            aa = dq.empty() ? 1 : 0;
            printf("%d\n", aa);
        }
        else if (str == "front")
        {
            aa = dq.empty() ? -1 : dq.front();
            printf("%d\n", aa);
        }
        else
        {
            aa = dq.empty() ? -1 : dq.back();
            printf("%d\n", aa);
        }
    }

    return 0;
}