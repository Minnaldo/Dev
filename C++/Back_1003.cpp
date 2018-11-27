#include <vector>
#include <utility>
#include <chrono>
#include <iostream>

using namespace std;

/** 백준_1003 문제 (https://www.acmicpc.net/problem/1003)
 *  * 피보나치 수열을 구현시, 0 or 1이 몇번 호출되는지 묻는 문제
 *  ! DP가 아닌 패턴을 찾는 문제였다
 *  ? 2차원 배열을 이용하여 풀이도 가능
 */

pair<int, int> p;
vector<pair<int, int>> arr(40, p); // pair 자료형이 들어있는 벡터 초기화

void solution(int n)
{
    for (int i = 2; i <= n; i++)
    {
        arr[i].first = arr[i - 1].first + arr[i - 2].first;
        arr[i].second = arr[i - 1].second + arr[i - 2].second;
    }
    cout << arr[n].first << " " << arr[n].second;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

    arr[0].first = 1;
    arr[0].second = 0;
    arr[1].first = 0;
    arr[1].second = 1;

    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        auto start = chrono::steady_clock::now();
        solution(n);
        auto end = chrono::steady_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start);
        cout<<"\t"<<"Duration : "<<duration.count()/1000000.0<<  " ms" << endl;
    }

    return 0;
}