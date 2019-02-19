#include <chrono>
#include <fstream>
#include <iostream>

/** 가장 긴 감소 수열 백준_11722 ( https://www.acmicpc.net/problem/11722 )
 *  * O(N^2) 방법
 */

using namespace std;

int dp[1001];

int solution(int *arr, int N)
{
    int answer = 1; // 가장 짧은 길이는 1이므로 1로 초기화
    for (int i = 1; i <= N; i++)
    {
        dp[i] = 1; // dp를 계속 초기화 해주어야 함 ==> 기본 길이는 1이기 때문에 현재 인덱스에서 더이상 증가 할 수열의 원소가 없을 경우 1을 리턴해야 하기 때문에
        for (int j = 1; j <= i; j++)
        {
            // TODO 조건문을 더 봐야할듯
            if (arr[i] < arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        if (answer < dp[i])
            answer = dp[i];
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    fstream fs("input.txt");

    chrono::system_clock::time_point start = chrono::system_clock::now();

    int N;
    fs >> N;

    int *arr = new int[N + 1];
    for (int i = 1; i <= N; i++)
    {
        fs >> arr[i];
    }
    chrono::system_clock::time_point end = chrono::system_clock::now();
    cout << solution(arr, N) << endl;

    chrono::duration<double> sec = end - start;
    cout << sec.count() << " sec" << endl;

    return 0;
}