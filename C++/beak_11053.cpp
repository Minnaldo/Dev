#include <fstream>
#include <iostream>

/** 가장 긴 증가하는 부분 수열 백준_11053 (https://www.acmicpc.net/problem/11053)
 *  * 참조 : (http://seungkwan.tistory.com/8)
 */

using namespace std;

int dp[1001];

int max(int a, int b)
{
    return a > b ? a : b;
}

// O(N log N)의 시간복잡도를 가지는 알고리즘을 구현하기 위해
// lower bound를 이용한다. ==> 정렬된 배열에서 어떠한 값 val의 lower bound란 배열을 정렬된 상태로 유지하면서, val이 삽입될 수 있는 위치들 중 가장 인덱스가 작은 것
// lower bound는 이진 탐색을 통해 log N 시간에 구할 수 있음, C++에서는 lower bound가 구현되어 있음

// O(N^2)의 시간복잡도를 가짐
int solution(int n, int *arr)
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
        ans = max(dp[i], ans);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    // string str="6 10 20 10 30 20 50";    //4
    // string str2 = "5 1 2 3 2 3";
    // stringstream ss;
    // ss.str(str2);

    ifstream fs("input.txt");

    int n;
    // cin >> n;

    // 이렇게 구현을 해야 파일의 끝까지 읽어들인다
    int *arr = new int[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        fs >> tmp;
        arr[i] = tmp;
    }
    cout << solution(n, arr) << endl;
    return 0;
}