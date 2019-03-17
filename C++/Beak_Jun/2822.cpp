#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int arr[9], ans[9];

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");

    for (int i = 1; i <= 8; i++)
    {
        fs >> arr[i];
    }

    int tmp = 0;
    auto begin = arr[0];

    for (int i = 1; i <= 5; i++)
    {
        auto itr = max_element(arr, arr + 8);
        tmp += *itr;
        *itr = -1;
        ans[(itr - &begin)] = (itr - &begin);
    }

    cout << tmp << endl;
    for (int i = 1; i < 5; i++)
    {
        cout << ans[i];
    }
    cout << ans[5] << endl;

    return 0;
}