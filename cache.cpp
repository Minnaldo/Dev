#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int lru(int cSize, vector<string> &cities)
{

    int time = 0;
    int quantity_city = cities.size();

    vector<string> cache(cSize);
    vector<int> remainTime(cSize);

    if (cSize > 0)
    { //캐시메모리 있을때
        reverse(cities.begin(), cities.end());

        for (int rTime = 0; rTime < quantity_city; rTime++)
        {
            if (find(cache.begin(), cache.end(), cities.back()) != cache.end())
            {
                cout << "Cache HIT!!" << endl;

                for (int i = 0; i < cSize; i++)
                {
                    if (cache.at(i) == cities.back())
                        remainTime[i] += 1;
                    cities.erase(cities.end());
                }

                time += 1;
            }
            else
            {
                cout << "Cache Miss" << endl;

                if (cache.empty())
                { // 캐시가 비어있는 상태
                    cache.at(0) = cities.back();
                    remainTime.at(0) = 0;
                    cities.erase(cities.end());
                }
                else if (!cache.empty())
                {
                    int tmpidx = 0;

                    for (int i = 0; i < cSize; i++)
                    {
                        if (remainTime[i] == *max_element(remainTime.begin(), remainTime.end()))
                            tmpidx = i;
                    }
                    remainTime.at(tmpidx) = 0;
                    cache.at(tmpidx) = cities.back();
                    cities.erase(cities.end());
                }
                else
                {
                    for (int i = 0; i < cSize; i++)
                    {
                        if (cache[i].empty() && remainTime[i] == 0)
                        {
                            cache[i] = cities.back();
                            cities.erase(cities.end());
                        }
                    }
                }

                time += 5;
            }

            for (int i = 0; i < cSize; i++)
            {
                cout << cache.at(i) << "\t" << remainTime.at(i) << endl;
            }
        }
    }
    else if (cSize == 0)
    { //캐시메모리 없을때
        time = 5 * quantity_city;
    }
    else
    {
        cout << "Error!!" << endl
             << "There is no Cache Memory!" << endl;
        return 0;
    }

    return time;
}

int main(int argc, char const *argv[])
{

    int answer = 0;
    int cacheSize = 3;
    vector<string> cities = {"pangyo", "seoul", "la", "newyork", "bundang", "pangyo"};

    answer = lru(cacheSize, cities);

    // reverse(cities.begin(), cities.end());
    // cities.pop_back();
    // cout << cities.size() << endl;
    // cout << cities.capacity() << endl;

    // for (int i = 0; i < cities.capacity(); i++)
    // {
    //     cout << cities.at(i) << endl;

    //     if (cities[i].empty())
    //     {
    //         cout <<"cities "<< i << " is Empty" << endl;
    //     }
    //     else
    //     {
    //         cout  <<"cities "<< i << " is not empty" << endl;
    //     }
    // }

    cout << "Answer : " << answer << endl;
    return 0;
}
