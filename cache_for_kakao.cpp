#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//가장 오래된 원소의 번호를 리턴
int calTime(int csize, vector<string> &cache1, vector<string> &cache2, vector<int> &lasttime)
{
    int idx = 0;

    for (int i = 0; i < csize; i++)
    {
        //cache2에 cache1의 원소가 있으면 +1 없으면 0
        if (find(cache1.begin(), cache1.end(), cache2[i]) != cache2.end())
        {
            lasttime[i] += 1;
        }
        else
        {
            lasttime[i] = 0;
        }
    }

    // TODO: lasttime 벡터 각 원소의 크기를 비교해 인덱스 리턴

    for (int i = 0; i < csize; i++)
    {
        for (int j = 0; j < csize; j++)
        {
            if (cache1[i] == cache2[j] && !cache1[i].empty())
            {
                lasttime[i] += 1;
            }
        }
    }

    for (int i = 0; i < csize; i++)
    {
        //가장큰 값의 인덱스 찾기
        if (lasttime[i] == *(max_element(lasttime.begin(), lasttime.end())))
            idx = i;
    }
    return idx;
}

//algorithm find
// find(vector.begin(), vector.end(), item)

//캐시 벡터에 들어온 시간 필요
// 벡터 복사. v1 ,v2를 비교해 이전과 같으면 1증가 아니면 0으로 초기화
//대소문자 구별 안함
int algol_LRU(int csize, vector<string> &city_list) //city_list에는 cities의 역순의 배열이 들어옴
{
    int time = 0;
    int listlen = city_list.size();
    vector<string> cache1(csize); //캐시메모리
    vector<string> cache2(csize); //원소 시간 계산을 위한 비교벡터
    vector<int> lasttime(csize);  //cache1에 각원소가 머문 시간 계산
    cout << "city_list size : " << listlen << "\tCache1 size : " << cache1.size() << endl;
    cache2.assign(cache1.begin(), cache1.end()); //cache1을 cache2에 복사    assign == 기존원소 제거후 임의의 값으로 n개의 원소 할당
    cout << "cache2 size : " << cache2.size() << endl;
    //city_list 뒤집힘 city_list.back == 주어진 벡터의 첫번째 원소

    if (csize > 0)
    {
        for (int i = 0; i < listlen; i++) //입력받은 원소의 개수만큼 반복
        {
            //cache hit == city_list.back() 에 해당하는 원소가 cache1에 있음
            //find
            if (find(cache1.begin(), cache1.end(), city_list.back()) != cache1.end())
            {
                cout << "Cache Hit!!" << endl;
                city_list.pop_back(); //가장 첫번째 원소 사라짐

                for (int hittime = 0; hittime < csize; hittime++)
                {
                    lasttime[hittime] += 1;
                }
            }
            //cache miss == city_list.back() 에 해당하는 원소가 cache1에 없음
            // cache1.find(city_list.back());
            else
            {
                cout << "Cache Miss" << endl;
                int tmpidx = 0; //원소가 추가된 캐시 배열의 인덱스

                if (cache1.empty())
                {
                    cache1[0] = city_list.back();
                    cache2[0] = city_list.back();
                    city_list.pop_back();
                }
                else if (!cache1.empty())
                {
                    //max_element의 반환형 itr
                    for (int aa = 0; aa < csize; aa++)
                    {
                        if (lasttime[aa] == *(max_element(lasttime.begin(), lasttime.end())))
                        {
                            cache1[aa] = city_list.back();
                            cache1[aa] = city_list.back();
                            city_list.pop_back();
                            lasttime[aa] = 0;
                        }
                        else
                        {
                            lasttime[aa] += 1;
                        }
                    }
                }
                else
                {
                    for (int bb = 0; bb < csize; bb++)
                    {
                        if( find(cache1.begin(), cache1.end(), cache1[bb].empty()) != cache1.end()){
                            cache1[bb] = city_list.back();
                            cache2[bb] = city_list.back();
                            city_list.pop_back();
                            lasttime[bb] = 0;
                        }
                    }
                }

                time += 5;
            }
        }
    }
    else    //csize = 0;
    {
        time = 5 * listlen;
    }

    if (city_list.empty())
    {
        return time;
    }
}

int main(int argc, char const *argv[])
{
    int answer = 0;
    int cacheSize = 3;
    vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};

    reverse(cities.begin(), cities.end());
    answer = algol_LRU(cacheSize, cities);
    if (cacheSize < 0 && cacheSize > 30)
    {
        cout << "Error" << endl;
        return 0;
    }

    cout << "Answer : " << answer << endl;
    return 0;
}
