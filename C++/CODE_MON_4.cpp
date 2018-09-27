#include <string>
#include <vector>
#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    int N;
    vector <vector <int> > directory, query;
    vector <int> answer;

    directory(
        vector <int> ({1,2}),
        vector <int> ({1,3}),
        vector <int> ({2,4}),
        vector <int> ({2,5})
    );
    query(
        vector <int> ({1,5})
        vector <int> ({2,5})
        vector <int> ({3,5})
        vector <int> ({4,5})
    );

    
    return 0;
}