<<<<<<< HEAD
#include <vector>
=======
>>>>>>> 3a86120b2d86ab7f9f845dd874e1487398d2c167
#include <iostream>

using namespace std;

<<<<<<< HEAD
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
    
    

=======
int fibo(int n)
{
    if(n<=2) return 1;
    return fibo(n-1) + fibo(n-2);
>>>>>>> 3a86120b2d86ab7f9f845dd874e1487398d2c167
}

int main()
{
<<<<<<< HEAD
    cout<<fibo(4);
=======
    cout<<fibo(3)<<endl;
>>>>>>> 3a86120b2d86ab7f9f845dd874e1487398d2c167
    return 0;
}