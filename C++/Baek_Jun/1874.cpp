#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    ios::sync_with_stdio(false);
    cin.tie();
    int T;
    fs >> T;
    while (T--)
    {
        string tmp;
        int cnt = 0;
        fs >> tmp;

        int size = tmp.size();
        if (size % 2 != 0)
        {
            printf("NO\n");
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (tmp[i] == '(')
                    cnt++;
                else
                    cnt--;
            }
            if (cnt == 0)
                printf("YES\n");
            else
                printf("NO\n");
        }

    }

    return 0;
}