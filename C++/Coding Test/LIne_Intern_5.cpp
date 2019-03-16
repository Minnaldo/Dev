#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int memo[200000];

int max(int a, int b)
{
    return a > b ? a : b;
}

int solution(int bro, int co)
{
    memo[bro] = 0;
    for (int i = bro + 1; i <= co; i++) //i는 2부터 ==> 첫번째는 한칸이동 외엔 못밟음
    {
        if (i - 1 > bro)
            memo[i] = min(memo[i - 1] + 1, memo[i]);
        if (i / 2 > bro)
            memo[i] = min(memo[i / 2] + 1, memo[i]);
    }

    return memo[co];
}

int main(int argc, char const *argv[])
{
    int C, B;
    cin >> C >> B;
    int acct = 0, cnt = 0;

    int cPos = C, bPos = B;

    while (cPos >= 0 && cPos <= 200000)
    {
        cout << "bPos : " << bPos << endl;
        cnt++;

        acct += 1;
        cPos += acct;
        // 브라운 증가
        //  -1 +1 2

        if (abs(cPos - bPos) == 1)
        {
            if (cPos < bPos)
                bPos -= 1;
            else if (cPos > bPos)
                bPos += 1;
        }
        else
        {
            if (acct % 2 != 0)
            {
                bPos *= 2;
            }
            else
            {
                if (cPos < bPos)
                    bPos -= 1;
                else if (cPos > bPos)
                    bPos += 1;
            }
        }

        if (cPos == bPos)
        {
            cout << cnt << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}