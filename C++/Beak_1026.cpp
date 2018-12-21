#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

/** 보물 백준_1026 (https://www.acmicpc.net/problem/1026)
 *  * 가장 큰것과 가장 작은것을 더한다?? ==> a, b 중 하나는 오름차순, 하나는 내림차순 정렬을 하여 결과를 도출한다
 */

int arr_size;

int desc(int a, int b)
{
    return a > b;
}

int solution(int *a, int *b)
{
    int ret = 0;
    sort(&a[1], &a[arr_size + 1]);
    sort(&b[1], &b[arr_size + 1], desc);
    for (int i = 1; i <= arr_size; i++)
    {
        ret += (a[i]*b[i]);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    ifstream fs("input.txt");
    // 예제) 18
    int n;
    fs >> n;
    arr_size = n;
    int *b = new int[n + 1];
    int *a = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        fs >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        fs >> b[i];
    }

    cout << solution(a, b) << endl;
    return 0;
}