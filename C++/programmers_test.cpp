#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string ans = "";
    int size = number.size();

    vector<int> arr;
    arr.reserve(size);

    // string to int
    for (char aa : number)
        arr.push_back(atoi(&aa));

    for (int i = 0; i < size; i++)
    {
        // n ~ n+k 이내에 arr[n]보다 큰 숫자를 만나면, arr[n]을 삭제
        // for (int j = i + 1; j <= i + k - 1; j++)
        // {
        auto itr = lower_bound(arr.begin() + i + 1, arr.begin() + i + k, arr[i]);
        if (itr != arr.end())
        {
            arr[i] = -1;
            k--;
        }
        // }

        if (k == 0)
            break;
    }

    for (int aa : arr)
        cout << aa << " ";
    cout << endl;

    for (int aa : arr)
    {
        if (aa > 0)
            ans += to_string(aa);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++)
    {
        string number;
        int k;

        cin >> number >> k;

        printf("#%d %s\n", tc, solution(number, k).c_str());
    }
    return 0;
}