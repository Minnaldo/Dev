#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int h, w, n, ans;
        scanf("%d %d %d", &h, &w, &n);

        ans = (n % h) * 100; // height
        ans += (n / h) + 1;  // distance

        printf("%d\n", ans);
    }
    return 0;
}