#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

/** 예산 문제(https://programmers.co.kr/learn/courses/30/lessons/43237)
 * *예산의 상한액을 구하는 문제, 이분탐색을 이용한다.
 * *동적 계획법을 이용하면 더욱 빠른시간 내에 풀 수 있을지도
 */

int solution(vector<int> budgets, int M)
{
    int size = budgets.size();
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += budgets[i];
    }

    if (M > sum)
    {
        return M;
    }
    else
    {
        int idx = size / 2 + 1;
        sum = 0;
        for (int i = idx + 1; i < size; i++)
        {
            budgets[i] = budgets[idx];
        }

        for (int i = 0; i < size; i++)
        {
            sum += budgets[i];
        }

        if(M < size)    //idx 재설정
        else
        {
            int budget = size - (idx+1) +M;

            if(M < budget)
            {
                budget += size - (idx+1);
            }
            else
            {
                //위 과정 반복
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr;
    int M;

    solution(arr, M);
}