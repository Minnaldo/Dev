#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

/** 가장 긴 증가하는 부분 수열 백준_11053 ( https://www.acmicpc.net/problem/11053 )
 *  * 참조 : (http://seungkwan.tistory.com/8)
 *  NOTE
 */

using namespace std;

int dp[1001];

int max(int a, int b)
{
    return a > b ? a : b;
}

// O(N log N) 시간의 알고리즘으로 구현하기 위해 Lower Bound 기법을 이용한다.
// 리스트 L을 업데이트하며 동작
// L[i] = 길이 i인 증가하는 부분 수열을 만들 수 있는 마지막 원소 중 가장 작은 값
// ==> L의 크기가 곧 현재까지 만들 수 있는 LIS의 길이이며, 처음에 빈 리스트 이용
// L을 업데이트 하는 방법 ==> L이 비어있거나, 현재 L의 마지막 원소보다 here이 클 경우 --> L의 뒤에 here 추가
//L이 비어있지 않거나, 현재 L의 마지막 원소보다 here이 작을 경우 --> L에서 here의 Lower Bound를 찾아서 그자리를 here로 바꾼다.
int solution2(int n, int *arr)
{
    int here, len;
    for (int i = 1; i <= n; i++)
    {
        here = arr[i]; // here ==> 현재 원소
        auto pos = lower_bound(dp + 1, dp + len + 1, here);
        *pos = here;
        if (pos == dp + len + 1)
            len++;
    }
    return len;
}

int P[1001];
void backtrace(int idx, int num)
{
    if (idx == 0)
    {
        return;
    }
    if (P[idx] == num)
    {
        backtrace(idx - 1, num - 1);
        cout << dp[idx] << " ";
    }
    else
    {
        backtrace(idx - 1, num);
    }
}

// O(N log N)의 시간복잡도를 가지는 알고리즘을 구현하기 위해
// lower bound를 이용한다. ==> 정렬된 배열에서 어떠한 값 val의 lower bound란 배열을 정렬된 상태로 유지하면서, val이 삽입될 수 있는 위치들 중 가장 인덱스가 작은 것
// lower_bound는 이분 탐색을 통해 log N 시간에 구할 수 있음, C++에서는 lower bound가 구현되어 있음
// O(N^2)의 시간복잡도를 가짐
int solution1(int n, int *arr)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int here = 0;
        for (int j = 1; j <= i; j++)
        {
            if (arr[i] > arr[j])
            {
                here = max(here, dp[j]);
            }
        }
        dp[i] = here + 1;
        // ans = max(dp[i], ans);
        ans = dp[i] > ans ? dp[i] : ans;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    string str = "6 10 20 10 30 20 50";
    string str2 = "5 5 4 3 2 1";
    stringstream ss;
    ss.str(str2);
    // ifstream fs("input.txt");

    int n;
    ss >> n;

    // 이렇게 구현을 해야 파일의 끝까지 읽어들인다
    int *arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        ss >> tmp;
        arr[i] = tmp;
    }
    arr[0] = 0;
    cout << solution2(n, arr) << endl;
    return 0;
}