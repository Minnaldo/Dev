#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int LRU(int cSize, vector<string> &cities)
{
    transform(cities.begin(), cities.end(), cities.begin(), ::tolower);
    reverse(cities.begin(), cities.end());

    int time = 0;
    int listSize = cities.size();
    string cityName;
    vector<string> cache(cSize, "\0");
    vector<int> cTime(cSize, 0);

    if (cSize > 0)
    {
        for (int i = 0; i < listSize; i++)
        {
            cityName = *(cities.end()-1);   //마지막 요소
            auto itr = find(cache.begin(), cache.end(), cityName);

            if (itr != cache.end()) //캐시에 도시 이름이 있을때 == cache hit
            {
                cout<<"Cache Hit"<<endl;
                time += 1;
            }
            else //캐시에 도시 이름이 없을때 == cache miss
            {
                cout<<"Cache Miss"<<endl;
                time += 5;
            }

            cities.pop_back();
        }
    }
    else //No Cache size
    {
        time = 5 * quantity_city;
    }

    return time;
}

int main(int argc, char const *argv[])
{

    int answer = 0;
    int cacheSize = 5;
    vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"};

    answer = LRU(cacheSize, cities);

    cout << "Answer : " << answer << endl;
    return 0;
}
