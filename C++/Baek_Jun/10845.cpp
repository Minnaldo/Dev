#include <iostream>
#include <vector>

using namespace std;

vector<int> queue;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int n, aa, tmp;
    string str;
    cin >> n;
    while (n--)
    {
        cin >> str;
        if (str == "push")
        {
            cin >> tmp;
            queue.push_back(tmp);
        }
        else if (str == "pop")
        {
            if (queue.empty())
                printf("-1\n");
            else
            {
                aa = queue.front();
                printf("%d\n", aa);
                queue.erase(queue.begin());
            }
        }
        else if (str == "size")
        {
            if (queue.empty())
                printf("%d\n", 0);
            else
            {
                aa = queue.size();
                printf("%d\n", aa);
            }
        }
        else if (str == "empty")
        {
            aa = queue.empty() ? 1 : 0;
            printf("%d\n", aa);
        }
        else if (str == "front")
        {
            aa = queue.empty() ? -1 : queue.front();
            printf("%d\n", aa);
        }
        else
        {
            aa = queue.empty() ? -1 : queue.back();
            printf("%d\n", aa);
        }
    }

    return 0;
}