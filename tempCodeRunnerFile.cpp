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
    int cTime = 1;
    queue<int> bridge;
    vector<int>::iterator itr = truck_weights.begin();
    int weightSum = 0;

    if (truck_weights.size() <= 1)
    {
        cTime += bridge_length;
        return cTime;
    }
    else
    {
        while (true)
        {
            if (bridge_length > bridge.size())
            {
                if (weightSum + *itr <= weight)
                {
                    weightSum += *itr;
                    bridge.push(*itr);
                    itr = truck_weights.erase(itr);
                }
                else
                {
                    bridge.push(0);
                }
            }
            else
            {
                if (bridge.front() == 0)
                {
                    bridge.pop();
                    continue;
                }
                else
                {
                    weightSum -= bridge.front();
                    bridge.pop();
                    if (weightSum + *itr <= weight && !truck_weights.empty())
                    {
                            weightSum += *itr;
                            bridge.push(*itr);
                            itr = truck_weights.erase(itr);
                        
                    }else{
                        bridge.push(0);
                    }
                }
            }
            if(truck_weights.empty()){
                cTime += bridge_length;
                return cTime;
            }
            cTime++;
        }
    }
}