#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int arr[102][102];

vector<int> rotate(vector<int> arr)
{
    int tmp = arr.front();
    // arr.erase(arr.begin());
    arr.assign(arr.begin() + 1, arr.end());
    arr.push_back(tmp);

    return arr;
}

int main(int argc, char const *argv[])
{
    int tmp = 3;
    for (int i = 0; i < 102; i++)
        fill_n(arr[i], 102, 5);
    for (int i = 0; i < 102; i++)
    {
        for (int j = 0; j < 102; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}