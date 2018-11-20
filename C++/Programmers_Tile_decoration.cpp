#include <vector>
#include <iostream>

using namespace std;

/**
 * * 동적계획법을 이용한다.(피보나치 수열 구하는데 이용)
 * ? 효율성문제 발생 ==> 시간이 문제?
 */

int arr[80];

void fibo(int n)
{
    int cnt = 1;
    while (cnt <= n)
    {
        if (cnt <= 2)
        {
            arr[cnt] = 1;
        }
        else
        {
            arr[cnt] = arr[cnt - 1] + arr[cnt - 2];
        }
        cnt++;
    }
}

long long solution(int N)
{
    fibo(N);

    int num1 = arr[N], num2 = arr[N-1];
    return (long long) (num1*2)+((num2+num1)*2);
}

int main(int argc, char const *argv[])
{
    // cout << solution(5) << endl;
    cout << solution(6) << endl;
    return 0;
}