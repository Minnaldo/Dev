#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector <string> strV;
    for(int i = 10; i>=1; i--){
        int tmp = n/i;
        strV.push_back(tmp);
        n -= (tmp*i);
    }
    
    for(int i = strV.size(); i>=1; i--){
        int tmp = i%10;
        
    }
    
    return answer;
}