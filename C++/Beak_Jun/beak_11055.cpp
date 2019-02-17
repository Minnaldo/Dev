#include <fstream>
#include <iostream>

/** 가장 큰 증가 부분 수열 백준_11055 ( https://www.acmicpc.net/problem/11055 )
 *  TODO
 *  REVIEW
 *  * 이전 문제( beak_11053 ) 에서는 최장 길이를 dp 배열에 저장하였다면, 해당 문제에서는 가장 큰 합을 저장한다
 */

using namespace std;

int dp[1001];

// Time Complexity = O(N^2)
int solution(int *arr, int N)
{
    int answer;
    dp[1] = arr[1];

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = dp[j] + arr[i];
            }
        }

        if (answer < dp[i])
            answer = dp[i];
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    // 1 100 2 50 60 3 5 6 7 8 // 113
    int *arr = new int[N + 1];

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    cout << solution(arr, N) << endl;
    return 0;
}