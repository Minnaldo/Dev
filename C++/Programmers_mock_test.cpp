#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/** 모의고사 프로그래머스_완전탐색_모의고사 (https://programmers.co.kr/learn/courses/30/lessons/42840)
 *  * 입력으로 들어오는 answers의 크기만큼만 비교하면 된다
 *  * 수포자들의 맞은 갯수가 들어있는 배열에서 최댓값을 찾은 후, 배열에 저장된 값이 이와 같으면 answer 벡터에 push_back 하여 이에 맞는 인원을 찾는다
 */

using namespace std;

vector<int> tmp;

void func(vector<int> supo, vector<int> answers)
{
    int cnt = 0;
    int ansSize = answers.size();
    int supoSize = supo.size();
    for (int i = 0; i < ansSize; i++)
    {
        if (answers[i % ansSize] == supo[i % supoSize])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    tmp.push_back(cnt);
}

vector<int> solution(vector<int> answers)
{
    vector<int> aa = {1, 2, 3, 4, 5};
    vector<int> bb = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> cc = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    func(aa, answers);
    func(bb, answers);
    func(cc, answers);

    auto itr = max_element(tmp.begin(), tmp.end());
    vector<int> answer;
    for (int i = 0; i < 3; i++)
    {
        if (tmp[i] == *itr)
        {
            answer.push_back(i % 3 + 1);
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, 3, 4, 5};  // 1
    vector<int> arr2 = {1, 3, 2, 4, 2}; // 1, 2, 3
    vector<int> arr3 = {4, 4, 4, 5, 1};
    vector<int> answer = solution(arr2);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}