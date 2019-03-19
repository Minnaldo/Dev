#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

/** 듣보잡 백준_1764 ( https://www.acmicpc.net/problem/1764 )
 *  * 시간이 오래걸리네? ( 0.3 ms )
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    string str;
    set<string> s;
    vector<string> arr;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        s.insert(str);
    }

    for (int i = 0; i < M; i++)
    {
        cin >> str;
        if (!s.insert(str).second)
        {
            arr.push_back(str);
        }
    }

    sort(arr.begin(),arr.end());
    int size = arr.size();
    cout << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}