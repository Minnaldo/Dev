#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000

vector<int> tobinary(int num)
{
    int tmp = num;
    vector<int> arr;
    while (tmp > 0)
    {
        if (tmp % 2 == 1)
            arr.push_back(1);
        else
            arr.push_back(0);

        tmp /= 2;
    }
    reverse(arr.begin(), arr.end());
    return arr;
}

int solution(int n)
{
    int answer = 0;
    vector<int> binary = tobinary(n);
    int nCount = count(binary.begin(), binary.end(), 1);

    for (int i = n + 1; i <= MAX; i++)
    {
        vector<int> tmp = tobinary(i);

        if (nCount == count(tmp.begin(), tmp.end(), 1))
        {
            answer = i;
            break;
        }
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    int n = 78;  // ans : 83
    int n2 = 15; // ans : 23

    cout << solution(n2) << endl;
    return 0;
}