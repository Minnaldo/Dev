#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

/**
 *
 */

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    int size = priorities.size();

    auto itr = upper_bound(priorities.begin() + location + 1, priorities.end(), priorities[location]);

    // cout << "priorities[location] : " << priorities[location] << endl;
    // cout << *(priorities.begin() + location + 1) << endl;
    // cout << "itr : " << *itr << endl;

    if (itr != priorities.end())
        for (itr; itr != priorities.end(); itr++)
            if (*itr >= priorities[location])
                answer++;

    itr = priorities.begin() + location;

    for (auto itr1 = priorities.begin(); itr1 != itr; itr1++)
        if (*itr1 > priorities[location])
            answer++;

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<int> aa = {2, 1, 3, 2, 4};
    vector<int> aa2 = {1, 1, 9, 1, 1, 1};
    cout << solution(aa, 2) << endl;
    return 0;
}