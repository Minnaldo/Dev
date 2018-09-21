#include <iostream>
using namespace std;

int* dec2bin(int* arr, int size){
    int temp, i = 0;
    int* bin[size];
    int* tepArr[size];

    temp = arr;

    for(i=0; i<size; i++){
        tmpArr[i] = temp%2;
        temp = temp/2;
    }

    for(int j = size; j>=0; j--){
        bin[j] = tmpArr[size-j];
        arr[j] = bin[j];
    }    

return arr;
}



int main(int argc, char const *argv[])
{
    int size, i, j = 0;

    //2차원 배열 선언
    int ** map1 = NULL;
    int ** map2 = NULL;

    int * dataArr1 = NULL;
    int * dataArr2 = NULL;

    cout<<"Plz input the size"<<endl;
    cin>>size;

    //2차원 배열의 행 갯수
    map1 = new int*[size];
    map2 = new int*[size];

    //행 갯수 * 열 갯수
    for(i = 0; i<size; i++){
        map1[i] = new int[size];
        map2[i] = new int[size];
    }

    //2차원 배열 초기화
    for(i = 0; i<size; i++){
        for(j = 0; j<size; j++){
            map1[i][j] = 0;
            map2[i][j] = 0;
        }
    }

    dataArr1 = new int[size];
    dataArr2 = new int[size];

    cout<<"Plz input data"<<endl;

    for(i = 0; i<size; i++){
        cin>>dataArr1[i];
    }
    for(i = 0; i<size; i++){
        cin>>dataArr2[i];
    }

    return 0;
}
