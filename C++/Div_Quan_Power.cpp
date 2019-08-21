
#include <iostream>

using namespace std;

int pow(int x, int n){
    if(n == 1)
        return x;

    if(n%2 ==0){
        return pow(x,n/2) * pow(x,n/2);
    }else{
return pow(x,n/2) * pow(x,n/2)*x;
    }
}

int main(int argc, char const *argv[])
{
    // Recursive_Power
    printf("%d", pow(3,3));
    return 0;
}