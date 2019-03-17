#include <algorithm>
#include <iostream>

using namespace std;

int arr[9], ans[6];

int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 8; i++)
    {
        scanf("%d", &arr[i]);
    }

    int tmp = 0;
    auto begin = &arr[0];
    for (int i = 1; i <= 5; i++)
    {
        auto itr = max_element(arr, arr + 9);   // max_element는 iterator를 반환한다.
        tmp += *itr;
        ans[i] = (itr - begin);
        *itr = -1;
    }

    sort(ans, ans + 6); // iterator가 없는 배열에서 sort 쓰는 법
    printf("%d\n", tmp);
    for (int i = 1; i < 5; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[5]);

    return 0;
}