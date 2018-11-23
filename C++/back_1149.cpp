#include <iostream>
#include <sstream>
// #include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    // ifstream is;
    // is.read(in_file,)
    stringstream ss;
    string in_file = "3 26 40 83 49 60 57 13 89 99";
    ss.str(in_file);
    int n,tmp;
    ss >> n;

    int **cost = new int *[n];

    for (int i = 0; i < n; i++)
    {
        cost[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            ss >> tmp;
            cost[i][j] = tmp;
        }
    }

    cout<< "N : "<<n<<endl;
    for(int i=0; i<n; i++ )
    {
        for(int j=0; j<n; j++ )
        {
            cout<<cost[i][j] <<" ";
        }
        cout<<endl;
    }

    return 0;
}