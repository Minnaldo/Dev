#include <iostream>

/** 10부제 백준_10797 ( https://www.acmicpc.net/problem/10797 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int N, ans=0;
    cin>>N;

    for(int i = 0; i<5; i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp == N)
        {
            ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}