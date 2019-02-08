#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

/**
 *  * map 자료구조를 이용하여 푼다.
 */

using namespace std;

// Double Linked List와 Map 자료구조를 이용하여 캐시를 구한다 ==> expectation Time Complexity = O(1)
int LRU(int cSize, vector<string> &cities)
{
    map<string, int> cacheMap;
    int dataSize = cities.size();
    int time = 0;

    for (int i = 0; i < dataSize; i++)
    {
        string inputData = cities[i];
        transform(inputData.begin(), inputData.end(), inputData.begin(), ::toupper);
        cout << "input data : " << inputData << endl;
        cout << "Map Size : " << cacheMap.size() << endl;
        if (cacheMap.size() + 1 <= cSize) // + 1 의 이유는 앞으로 들어올 데이터에 대한 크기를 더한 값을 미리 계산하여 캐시 미스시 데이터 교체를 할 지, 말 지를 결정한다
        {
            if (cacheMap.find(inputData) == cacheMap.end()) // 중복되는 키가 있는 지 없는지 확인, condition은 중복되는 키가 없을 경우
            {
                // cache miss
                cacheMap.insert(make_pair(inputData, 0));
                time += 5;
            }
            else
            {
                // cache hit
                cacheMap[inputData] = 0; // key : inputdata. value : 0 으로 수정
                time += 1;
            }
        }
        else // cachemap 의 사이즈가 주어진 캐시메모리 크기보다 클 때, 지워야 할 데이터를 판단후 지우고 새로 들어오는 데이터를넣어야 한다
        {
            if (cacheMap.find(inputData) == cacheMap.end()) // 자료구조에서 키로 데이터를 찾아, 있으면 iterator반환, 없으면 map.end()반환
            {
                //cache miss
                int mapSize = cacheMap.size();
                auto tmpItr = cacheMap.begin();
                auto itr = tmpItr;
                for (int j = 1; j < mapSize; j++)
                {
                    tmpItr++;
                    if (itr->second < tmpItr->second)
                    {
                        itr = tmpItr;
                    }
                }
                // 가장 오랫동안 있던 데이터를 지우고 새로운 데이터를 삽입
                cacheMap.erase(itr->first);
                cacheMap.insert(make_pair(inputData, 0));
                time += 5;
            }
            else
            {
                // cache hit
                cacheMap[inputData] = 0;
                time += 1;
            }
        }

        // 캐시메모리에 올라와 있는 데이터에 한하여 시간 추가
        auto mapItr = cacheMap.begin();
        for (int j = 0; j < cacheMap.size(); j++)
        {
            mapItr->second++;
            mapItr++;
        }

        cout << "current consuming time : " << time << endl;
    }

    return time;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    int answer = 0;
    int cacheSize = 5;
    vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"}; // anser : 52

    int cacheSize2 = 2;
    vector<string> cities2 = {"Jeju", "Pangyo", "NewYork", "newyork"};

    int cacheSize3 = 0;
    vector<string> cities3 = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA"};

    answer = LRU(cacheSize2, cities2);

    cout << "Answer : " << answer << endl;
    return 0;
}
