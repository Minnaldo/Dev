#include <algorithm>
#include <iostream>

/** K번째 수 백준_11004 ( https://www.acmicpc.net/problem/11004 )
 *  TODO
 */

using namespace std;

int arr[5000001];

// algorithm 헤더의 sort를 사용 ==> 시간이 오래걸림
int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    int n, c;
    scanf("%d %d", &n, &c);
    // fs >> n >> c;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        // fs >> arr[i];
    }

    sort(arr + 1, arr + n);

    printf("%d\n", arr[c]);

    return 0;
}