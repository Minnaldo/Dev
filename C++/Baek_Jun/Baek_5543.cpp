#include <fstream>
#include <iostream>
#include <vector>

/** 상근날드 백준_5543 ( https://www.acmicpc.net/problem/5543 )
 *
 */

using namespace std;

int min(int &a, int &b) { return a < b ? a : b; }

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    ios::sync_with_stdio(false);
    int N, answer = 4000;
    vector<int> arr;
    vector<int> arr2;

    for (int i = 0; i < 5; i++)
    {
        fs >> N;

        if (i < 3)
        {
            arr.push_back(N);
        }
        else
        {
            arr2.push_back(N);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            answer = min(answer, arr[i] + arr2[j] - 50);
        }
    }

    cout << answer << endl;

    return 0;
}