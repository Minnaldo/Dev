#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// TODO: FIXME:
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
        //가장 오래 있었던 값의 인덱스 찾기
        if (lasttime[i] == *(max_element(lasttime.begin(), lasttime.end())))
            idx = i;
    }
    return idx; //idx == 가장 오래사용되지 않은 원소의 인덱스 번호
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


    if (csize > 0)
    {
        for (int i = 0; i < listlen; i++) //입력받은 원소의 개수만큼 반복
        {
            //cache hit == city_list.back() 에 해당하는 원소가 cache1에 있음
            //find
            if (find(cache1.begin(), cache1.end(), city_list.back()) != cache1.end()) //city_list.back()의 원소가 있으면 true, 없으면 false
            {                                                                         //city_list.back() 원소가 cache1의 원소로 존재할 때 == cache hit상황
                cout << "Cache Hit!!" << endl;
                city_list.pop_back(); //가장 첫번째 원소 사라짐
                time += 1;
                for (int j = 0; j < csize; j++)
                { //머무른 시간 모두 증가
                    if (!cache1[j].empty())
                        lasttime[j] += 1;
                }
            }
            else
            { //cache miss == cache에 저장된 원소를 현재의 원소와 바꿔야 함
                // // cout << "Cache Miss" << endl;
                int tmpidx = 0;
                // // // tmpidx = calTime(csize, cache1, cache2, lasttime);

                // // for(int b = 0; b <csize; b++){
                // //     if(cache1[b].empty()){
                // //         cache1[b] = city_list.back();
                // //         city_list.pop_back();
                // //     }

                // }

                // for (int a = 0; a < csize; a++)
                // {
                //     //가장 오래 있었던 값의 인덱스 찾기
                //     if (lasttime[a] == *(max_element(lasttime.begin(), lasttime.end())))
                //         tmpidx = a;
                // }

                // cache1[tmpidx] = city_list.back();
                // lasttime[tmpidx] = 0;
                // city_list.pop_back();
                // time += 5;

                // //cache1의 내용 cache2로 복사
                // for (int h = 0; h < csize; h++)
                // {
                //     cache2[h] = cache1[h];
                // }

                if (cache1.empty())
                {
                    cache1[0] = city_list.back();
                    city_list.pop_back();
                }
                else if (!cache1.empty())
                {

                    for (int i = 0; i < csize; i++)
                    {
                        if (cache1[i] == *(max_element(cache1.begin(), cache1.end())))
                            tmpidx = i;
                    }

                    cache1[tmpidx] = city_list.back();
                    lasttime[tmpidx] = 0;
                    city_list.pop_back();
                    time += 5;
                }
                else
                {
                    for (int i = 0; i < csize; i++)
                    {
                        if (find(cache1.begin(), cache1.end(), NULL) != cache1.end())
                        {
                        }
                        else
                        {
                        }
                    }
                }
            }
        }
    }
    else
    {
        time = 5 * city_list.size();
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
    vector<string> cities =
        {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"};
    // {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};

    if (cacheSize < 0 && cacheSize > 30)
    {
        cout << "Error" << endl;
        return 0;
    }

    reverse(cities.begin(), cities.end());
    
    for(int i = 0; i < cities.size(); i++)
    {
        cout<<cities[i]<<"\t";
    }
    
    answer = algol_LRU(cacheSize, cities);

    cout << "Answer : " << answer << endl;
    return 0;
}
