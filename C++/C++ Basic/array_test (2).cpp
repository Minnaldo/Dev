#include <iostream>

/**
 *  NOTE this code is that generate the array by dynamic allocation
 */

using namespace std;

int *arrRcv(int *arr, int num)
{
    for (int i = 0; i < num; i++)
    {
        arr[i] = num * i;
        cout << arr[i] << endl;
    }

    return arr;
}

int main(int argc, char const *argv[])
{
    int size, i = 0;
    int *arr = NULL;
    int *testArr = NULL;

    cout << "plz input a array size" << endl;
    cin >> size;
    cout << endl;

    //creat Dynamic Pointer in C
    //int * n 크기의 배열을 가진 arr생성 (like arr = (int*)malloc(sizeof(int)*n) on C)
    arr = new int[size];
    testArr = new int[size];

    testArr = arrRcv(arr, size);

    // for(int j = 0; j<n; j++){
    //     arr[j] = j+1;
    // }

    cout << "the size of the arr : " << sizeof(arr) << endl;
    for (i = 0; i < size; i++)
    {

        cout << arr[i] << endl;
    }

    //arrRcv에서 반환된 배열
    cout << "the size of the testArr : " << sizeof(testArr) << endl;
    for (i = 0; i < size; i++)
    {

        cout << testArr[i] << endl;
    }

    delete[] arr;
    delete[] testArr;

    return 0;
}
