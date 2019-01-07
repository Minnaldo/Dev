#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 *  * 모든 상황을 보고 판단해야한다
 *  * [n][1] && [0][2] 가 0이면 아웃
 *  ? 스트라이크와 볼에 가중치 각각 2,1을 부여
 *  ? 가중치 순서대로 나열하여 바뀐것을 비교하며 답이 될 수 있는 것을 찾아간다
 *  ? 재귀적으로 풀면 어떨까?? like permutation
 */

using namespace std;

int solution(vector<vector<int>> baseball)
{
    int answer = 0;
    int bSize = baseball.size();
    int *temp = new int[bSize];

    for(int i = 0; i<bSize; i++)
    {
        temp[i] = (baseball[i][1] * 2) +(baseball[i][2] *1);
    }

    auto itr = max_element(temp, temp+bSize);

    if(*itr >= 5)
    {

    }
    else
    {

    }

    return answer;
}

int main(int argc, char const *argv[])
{

    vector<vector<int>> arr = {{{123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1}}};

    cout << solution(arr) << endl;
    return 0;
}
