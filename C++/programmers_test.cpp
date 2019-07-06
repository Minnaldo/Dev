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
        if (k > 1)
        {
            // n ~ n+k 이내에 arr[n]보다 큰 숫자를 만나면, arr[n]을 삭제
            for (int j = i + 1; j <= i + k - 1; j++)
            {
                if (arr[i] < arr[j])
                {
                    arr[i] = -1;
                    k--;
                    break;
                }
            }
        }
        else if (k == 1)
        {
            auto itr = min_element(arr.begin(), arr.end(), [](int tmp, int tmp2) {
                if (tmp >= 0 && tmp2 >= 0)
                {
                    return tmp < tmp2 ? true : false;
                }
            });
            if (itr != arr.end())
            {
                *itr = -1;
                k--;
            }
        }
        else
            break;
    }

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