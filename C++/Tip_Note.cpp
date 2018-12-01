#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);    // ! CPP의 iostream을 c의 stdio와 동기화 시켜주는 역할을 false

    int T;
    cin>>T;

    for(int i =0; i<T; i++)
    {
        int a, b;
        cin>>a>>b;
        cout<<a+b<<"\n";
    }

    return 0;
}