#include <algorithm>
#include <deque>
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
int attachBlock(int block, int direction)
{
    int tmp;
    switch (block)
    {
    case 1:
        tmp = (direction == 1 ? 3 : (direction == 2 ? 4 : (direction == 3 ? 2 : 1)));
        break;
    case 2:
        tmp = (direction == 1 ? 2 : (direction == 2 ? 4 : (direction == 3 ? 1 : 3)));
        break;
    case 3:
        tmp = (direction == 1 ? 4 : (direction == 2 ? 3 : (direction == 3 ? 1 : 2)));
        break;
    case 4:
        tmp = (direction == 1 ? 3 : (direction == 2 ? 1 : (direction == 3 ? 4 : 2)));
        break;
    }

    return tmp;
}
int main(int argc, char const *argv[])
{
    // int tmp = 3;
    // for (int i = 0; i < 102; i++)
    //     fill_n(arr[i], 102, 5);
    // for (int i = 0; i < 102; i++)
    // {
    //     for (int j = 0; j < 102; j++)
    //         cout << arr[i][j] << " ";
    //     cout << endl;
    // }

    // cout << attachBlock(1, 4) << endl;
    // int idx = 0;
    // while (idx <= 10)
    // {

    //     if (idx % 2 == 0)
    //     {
    //         cout << "2" << endl;
    //         idx++;
    //         continue;
    //     }
    //     idx++;
    // }

    vector<int> vec1 = {1, 2, 3, 4, 5, 6};
    vector<int> vec2 = {1, 1, 1, 1, 1, 1};

    for (int i = 0; i < vec1.size(); i++)
        cout << vec1[i] << " ";
    cout << endl;
    vec1.assign(vec2.begin(), vec2.end());
    for (int i = 0; i < vec1.size(); i++)
        cout << vec1[i] << " ";
    cout << endl;

    return 0;
}