#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(string dartResult){

    int answer=0;
    vector <string> arr(dartResult.size());
    vector <int> score(dartResult.size());

    score += atoi(arr.c_str());



}


int main(int argc, char const *argv[])
{
    vector <string> arr;

    arr = {"1S2D*3T","1D2S#10S","1D2S0T","1S*2T*3S","1D#2S*3S", "1T2D3D#", "1D2S3T*"};
    for(int i = 0; i<arr.size(); i++){
    solution(arr[i]);
    }
    return 0;
}

// 3 7 11
// 2 6 10