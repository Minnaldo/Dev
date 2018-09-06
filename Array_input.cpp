#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cout<<"input"<<endl;

    int a = 5;

    // cin>>a;

    int bin[a];

    for(int i = 0; i<a; i++){
        cin>>bin[i];
    }

    for(int j = 0; j<a; j++){
        cout<<bin[j]<<endl;
    }

    return 0;
}
