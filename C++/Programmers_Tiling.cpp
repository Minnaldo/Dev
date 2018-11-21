#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

/**
 * *
 */

int cache[100];

//2* width 크기의 사각형을 채우는 방법의 수 리턴
int tiling(int width)
{
    if (width <= 1)
        return 1;

    int &ret = cache[width];

    if (ret != -1)
        return ret;
    return ret = tiling(width - 2) + tiling(width - 1);
}

int main(int argc, char const *argv[])
{

    return 0;
}