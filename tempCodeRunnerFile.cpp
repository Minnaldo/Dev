#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int inner = 2*n -1;
    for(int i = 1; i<=n; i++)
    {
        for(int j = n+1;j>=0;j--)
        {
            if(i%3 == 1)
            {
                // 1개
                cout<<"*";
            }
            else if(i%3 == 2)
            {
                // 2개
                cout<<"* *";
            }
            else
            {
                // 5개
                cout<<"*****";
            }
            cout<<endl;
        }
    }
    return 0;
}