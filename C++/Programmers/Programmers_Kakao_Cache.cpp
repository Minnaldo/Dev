#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

/** 프로그래머스_캐시 (https://programmers.co.kr/learn/courses/30/lessons/17680)
 *  * map 자료구조를 이용, etc. queue & deque 등의 이용해서 해결 가능
 */

using namespace std;

// Double Linked List와 Map 자료구조를 이용하여 캐시를 구한다 ==> expectation Time Complexity = O(1)
int LRU(int cSize, vector<string> &cities)
{
    map<string, int> cacheMap;
    int dataSize = cities.size();
    auto itr = cities.begin();
    int time = 0;

    // cache Size가 0이면 계산 하나 마나
    if(cSize <= 0)
    {
        return dataSize*5;
    }

    for (itr; itr < cities.end(); itr++)
    {
        string inputData = *itr;
        transform(inputData.begin(), inputData.end(), inputData.begin(), ::toupper);
        cout << "input data : " << inputData << endl;
        cout << "Before Map Size : " << cacheMap.size() << endl;

        if (cacheMap.find(inputData) != cacheMap.end()) // cache hit
        {
            cacheMap[inputData] = 0;
            time += 1;
        }
        else // cache miss
        {
            if (cacheMap.size() < cSize)
            {
                cacheMap.insert(make_pair(inputData, 0));
            }
            else // 교체할 원소를 찾아야함
            {
                if(!cacheMap.empty()){
                auto tmpItr = cacheMap.begin()++;
                auto bigItr = cacheMap.begin();

                for (tmpItr; tmpItr != cacheMap.end(); tmpItr++)
                {
                    if (bigItr->second < tmpItr->second)
                    {
                        bigItr = tmpItr;
                    }
                }

                cacheMap.erase(bigItr);
                cacheMap.insert(make_pair(inputData, 0));}
            }
            time += 5;
        }
        cout << "After Map Size : " << cacheMap.size() << endl;
        cout << "current consuming time : " << time << endl;

        auto mapItr = cacheMap.begin();
        for (int j = 0; j < cacheMap.size(); j++)
        {
            mapItr->second++;
            mapItr++;
        }
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

    answer = LRU(cacheSize3, cities3);

    cout << "Answer : " << answer << endl;
    return 0;
}
