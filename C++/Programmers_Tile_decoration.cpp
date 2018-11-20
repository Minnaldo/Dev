#include <vector>
#include <iostream>

using namespace std;

/**
 * * 동적계획법을 이용한다.(피보나치 수열 구하는데 이용)
 * ? 효율성문제 발생 ==> 시간이 문제?
 */

long long arr[80];

void fibo(int n)
{
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

long long solution(int N)
{
    arr[0] = 1, arr[1] = 1;
    fibo(N);

    long long num1 = arr[N - 1], num2 = arr[N - 2];
    return (num1 * 4) + (num2 * 2);
}

int main(int argc, char const *argv[])
{
    cout << solution(5) << endl;
    cout << solution(6) << endl;
    return 0;
}