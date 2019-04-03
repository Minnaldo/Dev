#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

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
    for (int i = 0; i < 4; i++)
    {
        int ny = tmp * dir[i][0];
        int nx = tmp * dir[i][1];
        cout << ny << " " << nx << endl;
    }

    return 0;
}