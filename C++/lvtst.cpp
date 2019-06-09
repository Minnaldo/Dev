#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 *
 */

using namespace std;

vector<int> permu;
vector<int> pnum;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void savePermutation(string arr, int size)
{
    permu.push_back(stoi(arr));
}

// 조합 만들기
void permutation(string arr, int depth, int n, int r) // n : 후보군 배열 크기, depth : 현 시점에서 순열의 길이
{
    if (depth == r)
    {
        savePermutation(arr, r);
        return;
    }

    for (int i = depth; i < n; i++) // 한자리수의 순열을 만들때에 배열의 크기만큼 반복해줘야 모든 원소들을 돌아다닐 수 있다.
    {
        swap(arr[depth], arr[i]);
        permutation(arr, depth + 1, n, r);
        swap(arr[depth], arr[i]); // 배열을 원래대로 만들어준다
    }
}

int solution(string numbers)
{
    int answer = 0;
    for (int i = 0; i <= numbers.size(); i++)
        permutation(numbers, 0, numbers.size(), i);

    sort(permu.begin(), permu.end());
    permu.erase(unique(permu.begin(), permu.end()), permu.end());
    pnum.assign(permu.back(), 0);

    for (int aa : permu)
        cout << aa << " ";
    cout << endl;

    for (int i = 1; i < pnum.size(); i++)
    {
        pnum[i] = i + 1;
    }

    for (int i = 2; i <= pnum.size(); i++)
    {
        if (pnum[i - 1] != 0)
        {
            for (int j = i * 2; j <= pnum.size() + 1; j += i)
            {
                pnum[j - 1] = 0;
            }
        }
    }

    for (int aa : permu)
    {
        if (pnum[aa] != 0)
            answer++;
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    string nums = "17";
    string nums2 = "011";
    cout << solution(nums2) << endl;

    return 0;
}