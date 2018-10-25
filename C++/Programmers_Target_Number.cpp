#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

/** Programmers Target Number (https://programmers.co.kr/learn/courses/30/lessons/43165)
 * * DFS, '-'의 개수를 하나씩 늘려가며 계산한다  line 17 ~ line 23 재귀함수 사용(각각 상황에서 모두 분기함)
 * * line 27 ~ line 39는 트리 분기 완료시 타겟넘버와 일치하는지 확인
 * ! idx 변수의 사용 주의   idx++ 사용시 segfalut, 윗줄에 idx++연산 후 idx 사용시 쓰레기값 생성 꼭 idx+1 사용
 */

int TARGET_Num, cnt;

void bfs(vector<int> numbers, int idx)
{
    if (idx < numbers.size())
    {
        numbers[idx] *= 1;
        bfs(numbers, idx + 1);

        numbers[idx] *= (-1);
        bfs(numbers, idx + 1);
    }
    else
    {
        int sum = 0;

        for (int i = 0; i < numbers.size(); i++)
        {
            sum += numbers[i];
        }
        if (sum == TARGET_Num)
        {
            cnt++;
        }
    }
}

int solution(vector<int> numbers, int target)
{
    TARGET_Num = target;

    bfs(numbers, 0);

    return cnt;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 1, 1, 1, 1};
    int target = 3;
    cout << solution(arr, target) << endl;

    return 0;
}
