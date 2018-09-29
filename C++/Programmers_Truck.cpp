#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char const *argv[])
{
    int answer = 0;

    //EX 1)
    int bridge_length = 2;
    int weight = 10;
    int weightSum = 0;
    vector<int> truck_weights = {7, 4, 5, 6};
    vector<int> wait_truck;
    queue<int> britdge;

    //코드 성능 체크
    auto start = chrono::high_resolution_clock::now();
    //reverse와 같음   (뒤집어 복사)
    wait_truck.assign(truck_weights.rbegin(), truck_weights.rend());

    for (int i = 0; i < truck_weights.size(); i++)
    {        
        if(weightSum > weight){ //다리 무게 초과

        }else{  //다리 무게 감소

        }
        answer++;
    }



    auto end = chrono::high_resolution_clock::now();
    cout << "Time : " << (float)(end - start).count() / CLOCKS_PER_SEC << endl;
    cout << "Answer : " << answer << endl;
    return 0;
}
