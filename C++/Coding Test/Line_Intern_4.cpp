#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max(int &a, int &b) { return a > b ? a : b; }

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    ios::sync_with_stdio(false);
    int N;
    fs >> N;

    vector<int> arr(N + 1, 0);
    vector<int> arr2(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        fs >> arr[i];
    }

    for (int i = 1; i <= N; i++)
    {
        int curVal = arr[i], tmp = 0;
        for (int j = 1; j < i; j++)
        {
            if (i != j)
            {
                if (curVal <= arr[j])
                {
                    tmp = abs(j - i);
                    break;
                }
            }
        }
        int tmp1 = 0;
        for (int j = i + 1; j <= N; j++)
        {
            if (i != j)
            {
                if (curVal <= arr[j])
                {
                    arr2[i] = max(arr2[i], abs(j - i));
                    break;
                }
            }
        }
    }

    cout << *(max_element(arr2.begin(), arr2.end())) << endl;

    return 0;
}