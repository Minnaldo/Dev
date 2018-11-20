#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

/** N으로 표현 (https://programmers.co.kr/learn/courses/30/lessons/42895)
 * * 8개 이하의 N을 써서 number를 나타내라
 */

void dfs(int num)
{
    if (num < number)
    {
        int tmp += N;
        dfs(tmp);
        int tmp -= N;
        dfs(tmp);
        int tmp *= N;
        dfs(tmp);
        int tmp /= N;
        dfs(tmp);
    }
    else if (num == number)
    {
        if (cnt <= 8)
        {
            return cnt;
        }
        else
        {
            return (-1);
        }
    }
}

int solution(int N, int number)
{
    int answer = 0;
    return answer;
}

int main(int argc, char const *argv[])
{
    solution();
    return 0;
}