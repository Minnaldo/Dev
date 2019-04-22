#include <cmath>
#include <iostream>

using namespace std;

int x, y, w, h, ans;
int map[8][8];

int min(int &a, int &b) { return a < b ? a : b; }

int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d", &x, &y, &w, &h);

    int dst = abs(w - x);
    int dst2 = abs(h - y);

    ans = min(dst, min(dst2, min(x, y)));

    printf("%d\n", ans);

    return 0;
}