#include <iostream>
#include <sstream>
// #include <fstream>

using namespace std;

int dp[1000];   // 집의 수 <= 1000

int solution()
{
}

int main(int argc, char const *argv[])
{
    // ifstream is;
    // is.read(in_file,)
    stringstream ss;
    string in_file = "3 26 40 83 49 60 57 13 89 99";
    ss.str(in_file);
    int n, tmp;
    ss >> n;

    int **cost = new int *[n];

    for (int i = 0; i < n; i++)
    {
        cost[i] = new int[3]; //  n * 3 배열 동적 선언
        for (int j = 0; j < 3; j++)
        {
            ss >> tmp;
            cost[i][j] = tmp;
        }
    }
/*
    cout<< "N : "<<n<<endl;
    for(int i=0; i<n; i++ )
    {
        for(int j=0; j<3; j++ )
        {
            cout<<cost[i][j] <<" ";
        }
        cout<<endl;
    }
*/
    // 동적 할당 2차원 배열 메모리 해제
    for (int i = 0; i < n; i++)
    {
        delete[] cost[i];
    }
    delete[] cost;

    return 0;
}