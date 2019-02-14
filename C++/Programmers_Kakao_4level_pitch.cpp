#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int answer;

void funct(int n, int maxStar, int maxPlus)
{

    if (maxStar < 0)
    {
        return;
    }

    if (n == 1)
    {
        answer++;
        return;
    }
    funct(n / 3, maxStar - 1, maxPlus);
    funct(n - 1, maxStar, maxPlus - 1);
}

int solution(int n)
{
    answer = 0;
    int maxStar = (int)(log10((double)n) / log10(3.0)), maxPlus = maxStar * 2;
    funct(n - 2, maxStar, maxPlus - 2);

    return answer;
}

int main(int argc, char const *argv[])
{
    // int n = 15;
    // int n = 41;
    // int n = 2000000000;  //  segfault
    int n = 2147483647; //  segfault
    cout << solution(n) << endl;
    return 0;
}