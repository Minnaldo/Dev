#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 * TODO
 *  * 비교 정렬을 이용하여 정렬 후 값을 리턴
 *  * 자릿수를 맞춘 배열이 정렬될때 원래의 배열도 같은 인덱스가 정렬되도록 구현?
 */

using namespace std;

bool compare_idx(string a, string b)
{
    return a[0] < b[0];
}

bool compare_idx1(string a, string b)
{
    return a[1] < b[1];
}

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> numStr;
    int vecSize = numbers.size();
    vector<int> arr(vecSize, 0);

    for (int i = 0; i < vecSize; i++)
    {
        numStr.push_back(to_string(numbers[i]));

        // int strVecSize = numStr[i].size();

        // 자리수 정렬
        // for (int j = 0; j < 4 - strVecSize; j++)
        // {
        //     numStr[i] += "0";
        // }

        // arr[i] = stoi(numStr[i]);
    }

    sort(&numStr[0], &numStr[vecSize], compare_idx);

    for (int i = 0; i < vecSize - 1; i++)
    {
        if (numStr[i][0] == numStr[i + 1][0] && numStr[i].size() > 2 && numStr[i + 1].size() > 2)
        {
            if (numStr[i][1] < numStr[i + 1][1])
            {
                swap(numStr[i], numStr[i + 1]);
            }
        }
    }

    for (int i = 0; i < vecSize; i++)
    {
        cout << numStr[i] << endl;
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    vector<int> str = {3, 30, 34, 5, 9};
    cout << solution(str) << endl;
    return 0;
}