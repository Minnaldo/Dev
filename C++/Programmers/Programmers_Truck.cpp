#include <vector>
#include <iostream>
#include <queue>
#include <chrono>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights);

int main(int argc, char const *argv[])
{
    auto start = chrono::high_resolution_clock::now();
    
    cout << "T1 : " << solution(2, 10, {7, 4, 5, 6}) << endl;
    cout << "T2 : " << solution(100, 100, {10}) << endl;
    cout << "T3 : " << solution(100, 100, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}) << endl;

    auto end = chrono::high_resolution_clock::now();
    cout << "Code Duration Time : " << (float)(end - start).count() / CLOCKS_PER_SEC << endl;
}

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int cTime = 1;
    queue<int> bridge;
    vector<int>::iterator itr = truck_weights.begin();
    // vector <int>::iterator bitr = bridge.begin();
    int weightSum = 0;

    if (truck_weights.size() <= 1) //대기 트럭이 하나 일 때
    {
        cTime += bridge_length;
        return cTime;
    }
    else //대기 트럭이 하나가 아닐 때
    {
        cout << endl;
        while (true)
        {
            if (bridge_length > bridge.size())
            {
                if (weightSum + truck_weights.front() <= weight && !truck_weights.empty())
                {
                    cout << truck_weights.front() << " 삽입\t"
                         << "Time : " << cTime << endl;
                    //다리위에 올라간 트럭무게의 총합 = weightSum이 다리 하중보다 낮을때
                    weightSum += truck_weights.front();
                    bridge.push(truck_weights.front());
                    truck_weights.erase(truck_weights.begin());
                }
                else
                {
                    //트럭 무게 합이 다리하중보다 높을 때
                    cout << "0 삽입" << endl;
                    bridge.push(0);
                }
            }
            else
            {
                cout << "Front : " << bridge.front() << endl;

                if (bridge.front() == 0)
                {
                    bridge.pop();
                    cout << "0 삭제" << endl;
                    continue;
                }
                else
                {
                    weightSum -= bridge.front();
                    cout << bridge.front() << " 삭제\t"
                         << "Time : " << cTime << endl;
                    bridge.pop();

                    if (weightSum + truck_weights.front() <= weight && !truck_weights.empty()) //나가는 동시에 입장 가능
                    {
                        cout << truck_weights.front() << " 동시 삽입\t"
                             << "Time : " << cTime << endl;
                        weightSum += truck_weights.front();
                        bridge.push(truck_weights.front());
                        truck_weights.erase(truck_weights.begin());
                    }
                    else
                    {
                        bridge.push(0);
                    }
                }
            }

            cout << "Bridge Size : " << bridge.size() << endl;

            if (truck_weights.empty())
            {
                cTime += bridge_length;
                return cTime;
            }
            cTime++;
        }
    }
}