#include <iostream>

using namespace std;

int fibo(int n)
{
    if(n<=2) return 1;
    return fibo(n-1) + fibo(n-2);
}

int main()
{
    cout<<fibo(3)<<endl;
    return 0;
}