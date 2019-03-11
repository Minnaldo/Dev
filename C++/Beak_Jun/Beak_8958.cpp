#include <iostream>
#include <string>

/** OX퀴즈 백준_8985 ( https://www.acmicpc.net/problem/8958 )
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N, ans;
    cin >> N;

    for (int a = 0; a < N; a++)
    {
        ans = 0;
        string str;
        cin >> str;
        int size = str.size();

        for (int i = 0; i < size; i++)
        {
            if (str[i] == 'O')
            {
                int idx = i, cnt = 0;
                while (str[idx] != 'X' && idx < size)
                {
                    idx++;
                    cnt++;
                    ans += cnt;
                }
                i = idx;
            }
        }

        cout << ans << endl;
    }
    return 0;
}