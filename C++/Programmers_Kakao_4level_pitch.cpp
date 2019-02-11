#include <iostream>
#include <math.h>
#include <string>

using namespace std;

long long answer;

void funct(string array, int n, int starCount, int plusCount, long long Count)
{
    if (Count > n)
    {
        return;
    }

    else if ((log10(n) / log10(3)) > starCount)
    {
        return;
    }

    if (Count == n && (starCount * 2) == plusCount)
    {
        answer++;
        return;
    }
    else if (starCount * 2 >= plusCount)
    {
        funct(array + "+", n, starCount, plusCount + 1, Count + 1);
        funct(array + "*", n, starCount + 1, plusCount, Count * 3);
    }
}

long long solution(int n)
{
    answer = 0;

    funct("*", n, 1, 0, 3);

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