#include <sstream>
#include <iostream>

using namespace std;

/**
 *  ! 최대 행복도를 구하라
 *  * Dynamic Programming Problem
 *  * recursuion Fomular
 */

// 개설 교과목 수 최대 200,000개
int dp[200000];

int main(int argc, char const *argv[])
{
    string input = "2 2 4 0 2 1 1 1 3 1 -1";
    stringstream ss;
    ss.str(input);

    int lo, hi;
    // cin>>lo>>hi;
    ss>>lo>>hi;

    int m;
    // cin>>m;
    ss>>m;

    int **arr = new int* [m];

    for(int i =0; i<m; i++)
    {
        arr = new int* [2];
        int hak, hang;
        // cin>>hak>>hang;
        ss>>hak;
        ss>>hang;
        arr[i][0] = hak;
        arr[i][1] = hang;
    }

    for(int i = 0; i<m; i++)
    {
        cout<<arr[i][0]<<"  "<<arr[i][1]<<endl;
    }

    return 0;
}