#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int time;
vector<string> cache;
vector<int> remainTime;

int LRU(int cSize, vector<string> &cities)
{
    transform(cities.begin(), cities.end(), cities.begin(), ::tolower);

    int listSize = cities.size();
    string cityName;

    if (cSize > 0)
    {
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
