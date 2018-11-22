#include <iostream>

using namespace std;

int solution(int N)
{
    int cnt = 0;
    if((N%3) == 0)
    {
        N/=3;
        cnt++;
    }
    else if((N%2) == 0)
    {
        N/=2;
        cnt++;
    }
    else
    {
        N--;
        cnt++;
    }

    return cnt;
}

int main(int argc, char const *argv[])
{
    cout<<solution(10)<<endl;
    return 0;
}