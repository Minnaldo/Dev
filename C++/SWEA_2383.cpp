#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> people;
vector<int> stair(2);
int map[10][10];

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        int ans;
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &map[i][j]);
            }
        }


        printf("#%d %d\n", tc, ans);
    }
    return 0;
}