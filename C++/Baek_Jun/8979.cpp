#include <algorithm>
#include <fstream>
#include <iostream>

/** 올림픽 백준_8979 ( https://www.acmicpc.net/problem/8979 )
 *  TODO Think about another way to solve
 *
 */

using namespace std;

pair<pair<int, int>, pair<int, int>> arr[1001];

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    ios::sync_with_stdio(false);
    cin.tie();
    int N, K, ans = 0;
    fs >> N >> K;

    for (int i = 0; i < N; i++)
    {
        fs >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;
    }

    sort(arr, arr + N, [&K](pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
        if (a.first.second > b.first.second) // Gold
            return true;
        else if (a.first.second == b.first.second)
        {
            if (a.second.first > b.second.first)
                true;
            else if (a.second.first == b.second.first)
            {
                if (a.second.second > b.second.second)
                    return true;
                else if (a.second.second == b.second.second)
                    return (a.first.first == K);
            }
        }
        return false;
    });

    for (int i = 0; i < N; i++)
    {
        if (arr[i].first.first == K)
        {
            printf("%d\n", i + 1);
            break;
        }
    }

    return 0;
}