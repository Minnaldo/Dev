#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N = 5;
    int number = 12;
    int idx = 1;

    vector <int> cache;
    vector <int> num;

    //자릿수 구하기
    int tmp = number;
    while(tmp > 10){
        tmp = tmp/10;
        idx *= 10;
    }    
    cout<<"idx : " <<idx<<endl;

    if((number%10) == 1){ 
        number ;
    }


    

    return 0;
}
