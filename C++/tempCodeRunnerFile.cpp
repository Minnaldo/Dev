#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    vector <int> answer;
    vector <int> answers = {1,2,3,4,5};

    vector <int> supo1 = {1,2,3,4,5};   //5
    vector <int> supo2 = {2,1,2,3,2,4,2,5}; //8
    vector <int> supo3 = {3,3,1,1,2,2,4,4,5,5}; //10

    //확장하도록 만든다.

    auto itr1 = supo1.end() -1;
    auto itr2 = supo2.end() -1;
    auto itr3 = supo3.end() -3;

    if(itr1 == supo1.end()){
        // supo1.insert()
    }
    if(*itr2 != 2){
        supo2.insert(supo2.end(), 2);
    }else{
        supo2.insert(supo2.end(), 3);
    }
    // if(itr3 ==)
    return 0;
}