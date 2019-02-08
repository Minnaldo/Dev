#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int LRU(int cSize, vector<string> &cities)
{
    map<string, int> cacheMap;
    int time = 0;
    // auto citiesItr = cities.begin();
    // string inputData;

    for (int i = 0; i < cities.size(); i++)
    {
        string inputData = cities[i];

        transform(inputData.begin(), inputData.end(), inputData.begin(), ::toupper);

        if (cacheMap.size() < cSize)
        {
            if (cacheMap.find(inputData) == cacheMap.end())
            {
                cacheMap.insert(make_pair(inputData, 0));
                time += 5;
            }
            else
            {
                cacheMap[inputData] = 0;
                time += 1;
            }
        }
        else
        {
            if (cacheMap.find(inputData) == cacheMap.end())
            {
                auto tmpItr = cacheMap.begin()++;
                auto itr = cacheMap.begin();

                while (tmpItr != cacheMap.end())
                {
                    if (itr->second < tmpItr->second)
                    {
                        itr = tmpItr;
                    }
                    tmpItr++;
                }

                cacheMap.erase(itr->first);
                cacheMap.insert(make_pair(inputData, 0));
                time += 5;
            }
            else
            {
                cacheMap[inputData] = 0;
                time += 1;
            }
        }

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

    int answer = 0;
    int cacheSize = 3;
    vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"}; // anser : 50

    int cacheSize3 = 0;
    vector<string> cities3 = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA"};

    answer = LRU(cacheSize3, cities3);

    cout << "Answer : " << answer << endl;
    return 0;
}
