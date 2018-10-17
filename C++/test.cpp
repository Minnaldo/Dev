#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

int main()
{
    int length;
    for (int i = 1; i <= 10; i++)
    {
        scanf("%d", &length);
        char *a = new char[length];
        scanf("%s", a);
        // string str;
        // getline(cin, str);
        stack<char> s;

        for (int k = 0; k < length; k++)
        {
            if (a[k] == '(' || a[k] == '{' || a[k] == '[')
            {
                s.push(a[k]);
            }
            else
            {
                if (s.top() == '(')
                {
                    if (a[k] != ')')
                    {
                        printf("#%d %d\n", i, 0);
                        break;
                    }
                    else
                    {
                        s.pop();
                    }
                }
                else if (s.top() == '{')
                {
                    if (a[k] != '}')
                    {
                        printf("#%d %d\n", i, 0);
                        break;
                    }
                    else
                    {
                        s.pop();
                    }
                }
                else
                {
                    if (a[k] != ']')
                    {
                        printf("#%d %d\n", i, 0);
                        break;
                    }
                    else
                    {
                        s.pop();
                    }
                }
            }
        }

        if (s.empty())
        {
            printf("#%d %d\n", i, 1);
        }
        else
        {
            printf("#%d %d\n", i, 0);
        }
    }
    return 0;
}