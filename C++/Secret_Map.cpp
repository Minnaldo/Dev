#include <iostream>
using namespace std;

int main(){

    int n = 0;
    
    cout<<"Plz input value"<<endl;
    cin>>n;

    //입력수 판정문
    if(n<1 || n>16 ){
        cout<<"Error!! Plz, input correct integer"<<endl;
    }

    int arr1[n][n];     // map1
    int arr2[n][n];     // map2
    char mapArr[n][n];  //final map

    int *inputvalue[n];
    int *inputvalue2[n];
    int bin[n];
    int bin2[n];


    cout<<"Plz input the value of first Array, Each value separated to space"<<endl;
    for(int a = 0; a<n; a++){
        cin>>inputvalue[a];
    }

    cout<<endl<<"Plz input the value of second Array, Each value separated to space"<<endl;    
    for(int b = 0; b<n; b++){
        cin>>inputvalue2[b];
    }

    //두 2차원 배열 비교
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if((arr1[i][j] + arr2[i][j]) == 0 ){
                mapArr[i][j] = \0;
            }else{
                mapArr[i][j] = "#" ;
            }
        }
        cout<<endl;
    }

    return 0;
}

//10진수 -> 2진수
int dec2bin(int *decNum, int n){
    int temp = 0;
    int * bin[n], tempArr[n];

    temp = decNum;
    //2진수 계산
    for(int a = 0; a<n; a++){
        tempArr[a] = temp%2;
        temp = temp/2;
    }

    //자리수 뒤집기
    for(int b = n; b>=0; b--){
        bin[b] = tempArr[n-b];
    }

    return &bin;
}