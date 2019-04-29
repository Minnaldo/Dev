#include <iostream>
#include <vector>

/** View SWEA_1026 ( https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV134DPqAA8CFAYh&categoryId=AV134DPqAA8CFAYh&categoryType=CODE )
 *
 */

using namespace std;

int max(int &a, int &b) { return a > b ? a : b; }

int solution(vector<int> &arr, int len)
{
    int ret = 0;
    int size = len - 2;
    for (int i = 2; i < size; i++)
    {
        int maxH = max(arr[i - 2], max(arr[i - 1], max(arr[i + 1], arr[i + 2])));

        if (arr[i] - maxH > 0)
            ret += (arr[i] - maxH);
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    for (int tc = 1; tc <= 10; tc++)
    {
        int ans = 0;
        int len;
        scanf("%d", &len);

        vector<int> arr;
        arr.assign(len, 0);
        for (int i = 0; i < len; i++)
            scanf("%d", &arr[i]);

        ans = solution(arr, len);

        printf("#%d %d\n", tc, ans);
    }
    return 0;
}