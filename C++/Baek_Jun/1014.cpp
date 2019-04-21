#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int c, n, m;
int map[10][10], dir[4][2] = {{-1, -1}, {0, -1}, {-1, 1}, {0, 1}};

int solution()
{
    int cnt = 0;
    int cnt2 = 0;

    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
                if (map[j][i] == 0)
                    cnt++;
        }
        else
        {
            for (int j = 0; j < n; j++)
                if (map[j][i] == 0)
                    cnt2++;
        }
    }

    return cnt > cnt2 ? cnt : cnt2;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < str.size(); j++)
            {
                if (str[j] == '.')
                    map[i][j] = 0;
                else
                    map[i][j] = 1;
            }
        }

        int ans = solution();
        printf("%d\n", ans);

        memset(map, -1, sizeof(map));
    }
    return 0;
}