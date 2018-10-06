#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights);

int main(int argc, char const *argv[])
{
    cout << "T1 : " << solution(2, 10, {7, 4, 5, 6}) << endl;
    cout << "T2 : " << solution(100, 100, {10}) << endl;
    cout << "T3 : " << solution(100, 100, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}) << endl;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> arr;
    queue<int> bQue;
    vector<int>::iterator itr = truck_weights.begin();
    
    int cross_time = 1;
    int weight_sum = 0;

while (itr != truck_weights.end())
{
    if (weight >= weight_sum + *itr)
    {
        weight_sum += *itr;
        if (bQue.size() < bridge_length)
        {
            bQue.push(*itr);
            arr.push(cross_time);
        }
        else
        {
            weight_sum -= bQue.front();
            bQue.pop();
            if (bQue.empty())
            {
                break;
            }
        }
    }
    else
    {
        if ((arr.front() + bridge_length) == cross_time)
        {
            // weight_sum = 0;
            bQue.pop();
            arr.pop();
        }
        cross_time++;
        continue;
    }
    cross_time++;
    itr++;
}
int answer = cross_time;
    return answer;
}