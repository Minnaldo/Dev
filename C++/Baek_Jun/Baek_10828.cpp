#include <iostream>
#include <vector>

/** 스택 백준_10828 ( https://www.acmicpc.net/problem/10828 )
 *
 */

using namespace std;

vector<int> stack;

int main(int argc, char const *argv[])
{
    int C, tmp, aa;
    string str;
    scanf("%d", &C);

    while (C--)
    {
        cin >> str;
        if (str == "push")
        {
            scanf("%d", &tmp);
            stack.push_back(tmp);
        }
        else if (str == "pop")
        {
            if (stack.empty())
                printf("-1\n");
            else
            {
                aa = stack.back();
                printf("%d\n", aa);
                stack.pop_back();
            }
        }
        else if (str == "size")
        {
            if (stack.empty())
                printf("%d\n", 0);
            else
            {
                aa = stack.size();
                printf("%d\n", aa);
            }
        }
        else if (str == "empty")
        {
            aa = stack.empty() ? 1 : 0;
            printf("%d\n", aa);
        }
        else
        {
            aa = stack.empty() ? -1 : stack.back();
            printf("%d\n", aa);
        }
    }

    return 0;
}