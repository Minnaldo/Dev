#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

int arr[101][101];

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    int n, cnt = 100;
    fs >> n;

    int x, y, befx, befy;
    fs >> x >> y;

    for (int a = 1; a < n; a++)
    {
        befx = x, befy = y;
        fs >> x >> y;

        int tmpx = abs(befx - x), tmpy = abs(befy - y);

        if (tmpx >= 10 && tmpy >= 10)
        {
            // 범위 바깥일 때
            cnt += 100;
        }
        else if (tmpx == 0 || tmpy == 0)
        {
            // 완전히 들어왔을 때
            if (tmpx == 0 && tmpy == 0)
            {
                break;
            }
            // x / y 둘 중 하나만 겹쳤을 때
            if (tmpy == 0)
            {
                cnt += (tmpy * 10);
            }
            else if (tmpx == 0)
            {
                cnt += (tmpx * 10);
            }
        }
        else
        {
            // 걸칠 때
            if (befx < x)
            {
                if (befy < y)
                    cnt -= (((befx + 10) - x) * ((befy + 10) - y));
                else
                    cnt -= (((befx + 10) - x) * ((y + 10) - befy));
            }
            else
            {
                if (befy < y)
                    cnt -= (((x + 10) - befx) * ((befy + 10) - y));
                else
                    cnt -= (((x + 10) - befx) * ((y + 10) - befy));
            }
        }
    }

    cout << cnt << '\n';
}