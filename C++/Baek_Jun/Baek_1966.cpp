#include <algorithm>
#include <iostream>
#include <vector>

/** 프린터 큐 백준_1966 ( https://www.acmicpc.net/problem/1966 )
 *  * pair 선언을 통해 현재 원하는 문서 표시 ( pair->second == 1 일 경우 원하는 문서 )
 *  * 문제 요구조건에 따라 진행 -> find_if를 통해 큰값을 찾고, 있으면 push_back 후 erase
 *  * 큰 값이 없으면 erase 하면서 ans 1 증가
 *  * pair->second값이 1일 때 반복문을 종료하는데, 종료전 1을 해줘야 출력 순서가 됨
 */

using namespace std;

vector<pair<int, int>> arr;

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int n, m, ans = 0, chk; // n : 문서의 수, m : 궁금한 문서의 현재 큐의 위치
        scanf("%d %d", &n, &m);
        arr.assign(n, make_pair(0, 0));
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        arr[m].second = 1;

        if (n == 1)
        {
            ans = 1;
        }
        else
        {
            // main routine
            while (!arr.empty())
            {
                chk = arr.front().first;
                auto itr = find_if(arr.begin(), arr.end(), [&chk](pair<int, int> a) { return chk < a.first ? true : false; });
                if (arr.end() != itr)
                {
                    arr.push_back(arr.front());
                    arr.erase(arr.begin());
                }
                else
                {
                    if (arr.front().second != 1)
                    {
                        arr.erase(arr.begin());
                        ans++;
                    }
                    else
                    {
                        // 1 증가를 안해주면 부족하게 됨
                        ans++;
                        break;
                    }
                }
            }
        }
        printf("%d\n", ans);
        arr.clear();
    }
    return 0;
}