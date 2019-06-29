#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int func(int a, int b)
{
    return a + b;
}

int main(int argc, char const *argv[])
{
    int aa, bb;

    printf("합을 구할 값을 입력해 주세요\n");

    scanf("%d %d", &aa, &bb);

    int (*ptrfunc)(int, int) = func;

    printf("합은 : %d\n", ptrfunc(aa, bb));
    return 0;
}