#include <vector>
#include <iostream>
#include <queue>
#include <chrono>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights);

int main(int argc, char const *argv[])
{
    cout << "T1 : " << solution(2, 10, {7, 4, 5, 6}) << endl;
    cout << "T2 : " << solution(100, 100, {10}) << endl;
    cout << "T3 : " << solution(100, 100, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}) << endl;
}

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    vector<vector<int>> info(truck_weights.size(), vector<int>(2, 0));
    vector<int>::iterator itr = truck_weights.begin();
    queue<int> bridge;
    int weightSum = 0;
    int cTime = 0;

    do
    {
        if (weightSum + *itr <= weight)
        {
            //Enter
            if (bridge.size() <= bridge_length)
            {
                weightSum += *itr;
                bridge.push(*itr);
                itr++;
            }
        }
        else
        {
            //Not Enter
        }

        cTime++;
    } while (!bridge.empty());

    answer = cTime;
    return answer;
}