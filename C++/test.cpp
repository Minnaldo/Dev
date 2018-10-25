#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

/** Programmers Target Number (https://programmers.co.kr/learn/courses/30/lessons/43165)
 * * DFS를 이용, '-'의 개수를 하나씩 늘려가며 계산한다
 */

int way_Quantity;
vector<bool> visit(20, false);

int solution(vector<int> numbers, int target)
{
    int cnt=0, chkSub=0;
    int vnum = numbers.size();
    int cal_cnt = (int)pow((double)vnum, 2.0);  //제곱 pos(x,y) == x^y

    while (cnt <= vnum)
    {
        int cur_sum = 0;

        for (int i = 0; i < cnt; i++)
        {
            if (!visit[i])
            {
                cur_sum -= numbers[i];
                visit[i] = true;
            }
        }

        for (int i = cnt; i < vnum; i++)
        {
            if (!visit[i])
            {
                cur_sum += numbers[i];
                visit[i] = true;
            }
        }

        if (visit[vnum - 1]) //말단노드까지 전부 끝낫을때 비교
        {
            if (cur_sum == target)
            {
                way_Quantity++;
            }
            fill(visit.begin(), visit.end(), false);
        }

        cnt++;
    }

    return way_Quantity;
}

int main(int argc, char const *argv[])
{
    vector<int> number = {1, 1, 1, 1, 1};
    int target = 3;
    cout << solution(number, target) << endl;
}