#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int n, ans, s;
int arr[50];

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    int tc = 0;
    scanf("%d", &tc);

    while (tc--)
    {
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        scanf("%d", &s);

        int idx = 0;
        int cnt = 0;
        bool flag = false;
        while (cnt < s)
        {
            if (arr[idx] < arr[idx + 1])
            {
                swap(arr[idx], arr[idx + 1]);
                cnt++;
                idx++;
                flag = true;
            }

            if (idx == n - 2)
            {
                idx = 0;
                if (!flag)
                    break;
            }
            else
                idx++;
            flag = false;
        }

        for (int i = 0; i < n - 1; i++)
            printf("%d ", arr[i]);
        printf("%d\n", arr[n - 1]);
    }

    return 0;
}