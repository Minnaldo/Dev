#include <vector>
#include <iostream>

int dp[2][20000];

using namespace std;

int solution(int n, vector<vector<int>> edge)
{

}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = {{{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}}};
    int n = 6;
    cout << solution(n, arr) << endl;
    return 0;
}