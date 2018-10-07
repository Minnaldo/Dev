#include <string>
#include <vector>
#include <iostream>

using namespace std;

solution (vector <int> prices);

int main(int argc, char const *argv[])
{
    cout<<solution(vector <int> prices = {498, 501, 470, 489})<<endl;
    return 0;
}


vector<int> solution(vector<int> prices) {
    vector<int> answer;    
    vector<int> arr;    
    
    for(int i =0; i<prices.size(); i++)
    {
        int tmp = i + 1;
        
        if(i != prices.size()){
            for(int j = tmp; j<prices.size(); j++)
            {
                if(prices[tmp] >prices[j])
                {
                    if(j != prices.size())
                    {
                        answer.push_back(j-i);        
                        continue;
                    }  else{
                        answer.push_back(0);
                    }
                } 
            }
        }
    }
    return answer;
}