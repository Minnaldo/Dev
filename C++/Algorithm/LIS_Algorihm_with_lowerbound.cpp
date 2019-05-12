#include <algorithm>
#include <iostream>
#include <vector>

/** Get LIS with Lower_bound
 *  * algorithm 헤더의 lowerbound를 이용하여 LIST를 구한다
 *  * answer를 업데이트 할 때 --> answer가 비어있거나, 현재 값이 answer.back()보다 크면, answer의 가장 뒤에 삽입
 *  * lowerbound가 존재하면, 해당 위치에 삽입
 */

using namespace std;

vector<int> arr, answer;
int n;

int solution()
{
    for (int i = 0; i < n; i++)
    {
        int cur = arr[i];

        if (answer.empty() || answer.back() < cur)
        {
            answer.push_back(cur);
        }
        else
        {
            auto itr = lower_bound(answer.begin(), answer.end(), cur);
            *itr = cur;
        }
    }

    return answer.size();
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    int tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    // LIS길이를 출력한다.
    cout << solution() << endl;
    return 0;
}