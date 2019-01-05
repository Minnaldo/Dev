#include <vector>
#include <string>
#include <iostream>

using namespace std;

int data[2] = {1, 7};
int flag[2];

void powerSet(int n, int depth)
{
    if(n==depth)
    {
        for(int i = 0; i<n; i++)
        {
            if(flag[i] ==1)
            cout<<data[i];
        }
        cout<<endl;
        return;
    }
    flag[depth]=1;
    powerSet(n,depth+1);
    flag[depth]=0;
    powerSet(n,depth+1);
}

int main(int argc, char const *argv[])
{
    powerSet(2,0);
    return 0;
}