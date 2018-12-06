#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num = 29;
    for(int i = 28; i>=13; i--)
    {
        num *= i;

    }

    cout<<num<<endl;
    return 0;
}