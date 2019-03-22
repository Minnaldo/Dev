#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/** 1011
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int x, y, T;
    cin >> T;

    for (int a = 0; a < T; a++)
    {
        cin >> x >> y;
        int cnt = 0;
        int dis = y - x;
        if (dis % 2 != 0)
        {
            int mid = dis / 2;
            for (int i = x; i <= mid + 1; i++)
            {
            }
            for (int i = mid + 1; i <= y; i++)
            {
            }
        }
        else
        {
            int mid = dis / 2;
            int k = 1;
            for (int i = x; i <= mid; i += k)
            {
                k++;
                cnt++;
            }
            cnt *= 2;
        }

        cout << cnt << endl;
    }
    return 0;
}