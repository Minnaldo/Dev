#include <iostream>
#include <string>
#include <vector>

/**
 *
 */

using namespace std;

int tc;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int solution(vector<int> &n, int c)
{
    int ret = 0;
    return 0;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++)
    {
        int ans = 0;
        int num, chance;
        scanf("%d %d", &num, &chance);
        vector<int> arr;
        string str = to_string(num);
        for (int i = 0; i < str.size(); i++)
            arr.push_back(str[i] - '0');

        ans = solution(arr, chance);

        printf("#%d %d\n", t, ans);
    }
    return 0;
}