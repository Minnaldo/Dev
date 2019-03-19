#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/** 백준_1181 don't use set .ver
 *  * this code uses less memory
 */

using namespace std;

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    ios::sync_with_stdio(false);

    auto start = chrono::system_clock::now();

    int N;
    fs >> N;

    vector<string> arr;
    for (int i = 0; i < N; i++)
    {
        fs >> arr[i];
    }

    sort(arr.begin(), arr.end(), [](string str1, string str2) {
        if (str1.size() == str2.size())
        {
            return str1.compare(str2) < 0 ? true : false;
        }
        return str1.size() < str2.size() ? true : false;
    });

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    auto itr = arr.begin();
    for (itr; itr != arr.end(); itr++)
    {
        cout << *itr << "\n";
    }

    auto end = chrono::system_clock::now();
    chrono::duration<double> sec = end - start;
    cout << sec.count() << " sec" << endl;

    return 0;
}