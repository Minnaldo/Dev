#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/** * 프로그래머스 완전탐색, 소수찾기
 *  * 가능한 원소의 조합을 구해야 한다. --> 조합 이용
 *  * 가능한 수의 조합을 찾고 이것이 소수인지 판별한다.
 */

using namespace std;

vector<int> vec;

void combi(int *arr, int idx, int n, int r, int target)
{
    if (r == 0)
        return;
    else if (target == n)
        return;
    else
    {
        vec.push_back(target);
        combi(arr, idx + 1, n, r - 1, target + 1);
        combi(arr, idx, n, r, target + 1);
    }
}

int solution(string numbers)
{
    int answer = 0;
    int size = numbers.size();
    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = (int)numbers[i] - 48;
    }

    for (int i = 1; i <= size; i++)
    {
        combi(arr, 0, size, i, 0);
    }

    for(int i = 0; i<size; i++)
    {
        cout<<vec[i]<<endl;
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    string str = "17";
    solution(str);
    return 0;
}