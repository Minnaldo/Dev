#include <vector>
#include <iostream>

using namespace std;

vector <int> memo;

int fibo(int n)
{
    if(n>2 && memo.empty())
    {
        memo.push_back(fibo(n-1) + fibo(n-2));
    }
    
    if(n<2)
    {
        return 1;
    }
    
    else
    {
        return fibo(n-1) + fibo(n-2);
    }
    
    

}

int main()
{
    cout<<fibo(4);
    return 0;
}