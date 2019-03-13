#include <iostream>

/** 분수 찾기 백준_1193 ( https://www.acmicpc.net/problem/1193 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N, child = 1, parent = 1;
    cin >> N;

    int idx = 2, tmp = 1;
    if (N != 1)
    {
        while (true)
        {
            tmp += idx;

            if (N <= tmp)
            {
                // N이 현재 줄에서 몇번째에 존재하는 지 판단
                int cnt = N - (tmp - idx) - 1;
                // find the range of positon of N
                if (idx % 2 == 0)
                {
                    // idx is even ==> idx is the start of child
                    parent = idx - cnt;
                    child = 1 + cnt;
                    break;
                }
                else
                {
                    // idx is odd ==> idx is the start of parent
                    child = idx - cnt;
                    parent = 1 + cnt;
                    break;
                }
            }

            idx++;
        }
    }

    cout << child << "/" << parent << endl;
    return 0;
}