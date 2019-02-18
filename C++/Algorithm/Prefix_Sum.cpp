#include <iostream>

/**
 *  * 정렬되지 않은 정수가 들어있는 배열이 존재할 때, 요청이 들어오는 a ~ b 의 합을 구하라
 */

using namespace std;

int arraySize;
int *sumArr;

int solution(int *arr, int a, int b)
{
    // 각 배열의 값들의 누적합을 저장해둔다. sumArr[i] = arr[0] ~ arr[i] 의 합
    for(int i = 0; i < arraySize; i++)
    {
        if( i == 0 )
        {
            sumArr[i] = arr[i];
        }
        else
        {
            sumArr[i] = sumArr[i-1] + arr[i];
        }
    }


    // 구하려는 부분합을 구한다

    int answer = 0;
    return sumArr[b] - sumArr[a-1]; // a ~ b 구간의 부분 합
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    arraySize = N;
    int *arr = new int[N];
    sumArr = new int [N];

    // a, b 는 0 ~ N-1 사이의 값
    int a, b;
    cin >> a >> b;

    cout << solution(arr, a, b) << endl;

    return 0;
}
