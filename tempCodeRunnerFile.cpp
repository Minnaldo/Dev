#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    vector < vector <int> > vec(4, vector<int>(4,0));

    
    int i =0;
    while(!vec.empty()){
        vec.pop_back();
        i++;
        cout<<i<<endl;
    }
    
    
    return 0;
}
