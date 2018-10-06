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
    vector<int> rtruck_weight;

    rtruck_weight.assign(truck_weights.rbegin(), truck_weights.rend());
    vector<int>::reverse_iterator itr = rtruck_weight.rbegin();
    queue<int> bridge;
    int weightSum = 0;
    int cTime = 1;

    while (true)
    {
        //IN
        if (weightSum + *itr <= weight)
        {
            if (bridge.size() <= bridge_length)
            {
                cout<<"2"<<*itr<<endl;
                bridge.push(*itr);
                itr++;
            }
            else
            {
                continue;
            }

            if(bridge.empty() && itr == rtruck_weight.rend()){
                break;
            }
        }
        //OUT
        else
        {
            itr--;
        }
    }

    int answer = cTime;
    return answer;
}