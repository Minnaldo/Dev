#include <vector>
#include <iostream>
#include <queue>
#include <chrono>

using namespace std;

int main(int argc, char const *argv[])
{
    int answer = 0;
    //EX 1)
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = {7, 4, 5, 6};

    queue<int> arr;
    queue<int> bQue;
    vector<int>::iterator itr = truck_weights.begin();
    int cross_time = 1;
    int weight_sum = 0;
    int tmpidx = 0;
    auto start = chrono::high_resolution_clock::now();

    while (itr != truck_weights.end())
    {

        if (weight >= weight_sum + *itr)
        {
            weight_sum += *itr;
            if (bQue.size() < bridge_length)
            {
                bQue.push(*itr);
                arr.push(cross_time);
                cout << "the truck is in the bridge : " << *itr << endl;
            }
            else
            {
                int tmp = bQue.front();
                weight_sum -= tmp;
                cout << "Crossed over truck : " << tmp << endl;
                bQue.pop();
                if (bQue.empty())
                {
                    break;
                }
            }
            cout << tmpidx << "번 째 Q 사이즈 : " << bQue.size() << endl;
            tmpidx++;
        }
        else
        {
            if ((arr.front() + bridge_length) == cross_time)
            {
                weight_sum = 0;
                cout << "Crossed over truck : " << bQue.front() << endl;
                bQue.pop();
                arr.pop();
            }
            cross_time++;
            continue;
        }
        cross_time++;
        itr++;
    }
    answer = cross_time;

    //프로그램 실행시간 체크
    auto end = chrono::high_resolution_clock::now();
    cout << "Duration Time : " << (float)(end - start).count() / CLOCKS_PER_SEC << " sec" << endl;
    cout << "Answer : " << answer << endl;
    return 0;
}
