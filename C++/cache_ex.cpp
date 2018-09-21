#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int cSize, ans = 0;     //ans = time, cSize = cache size
    vector<string> lru =  {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"};
    
    cSize = 5;
    cin.ignore(256, '\n');
    
    while (true)
    {
        string input;
        getline(cin, input);
        int lruSize = lru.size();
        
        if (input == "\0") break;
        
        transform(input.begin(), input.end(), input.begin(), ::tolower);    //문자열 모두 소문자로
        
        auto it = find(lru.begin(), lru.end(), input);  //type of the it is iterator
        if(it != lru.end()) //iterator가 lru의 마지막다음 값을가리키지 않을 때 = 캐시 적중
        {
            ans += 1;
            lru.erase(it);
        }
        else    //캐시 미스
        {
            ans += 5;
            if (cSize == lruSize && cSize != 0)
                lru.erase(lru.end());
        }
        
        if (cSize != 0) lru.insert(lru.begin(), input);
    }
    
    cout << ans;
    
    return 0;
}