#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 *  * 2차원 배열을 정렬하는 법
 */

using namespace std;

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    ios::sync_with_stdio(false);

    int N;
    fs >> N;

    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++)
    {
        fs >> arr[i].first;
        fs >> arr[i].second;
    }



    for (int i = 0; i < N; i++)
    {
        cout << arr[i].first << " " << arr[i].second << endl;
    }

    return 0;
}