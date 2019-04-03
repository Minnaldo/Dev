#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

/**
 *  * n/4 만큼 회전하면 계속 같은 숫자가 나온다!
 */

using namespace std;

long long solution(vector<long long> vec, int n, int k)
{
    int oneSize = n / 4;
    vector<long long> answer;

    for (int i = 0; i < oneSize; i++)
    {
        long long num1 = 0, num2 = 0, num3 = 0, num4 = 0;
        auto itr = vec.begin();
        for (int i = 0; i < oneSize; i++)
        {
            num1 += *itr * pow(16, oneSize - i - 1);
            num2 += *(itr + oneSize) * pow(16, oneSize - i - 1);
            num3 += *(itr + (oneSize * 2)) * pow(16, oneSize - i - 1);
            num4 += *(itr + (oneSize * 3)) * pow(16, oneSize - i - 1);
            itr++;
        }
        answer.push_back(num1);
        answer.push_back(num2);
        answer.push_back(num3);
        answer.push_back(num4);

        long long tmp = vec.front();
        vec.erase(vec.begin());
        vec.push_back(tmp);
    }

    sort(answer.rbegin(), answer.rend());
    unique(answer.begin(), answer.end());
    return answer[k - 1];
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        int n, k;
        long long ans = 0;

        scanf("%d %d", &n, &k);
        // char *str = new char[n + 1];
        char str[28];
        scanf("%s", str);
        vector<long long> vec;
        for (int i = 0; i < n; i++)
        {
            int tmp = str[i] - '0';
            if (tmp >= 0 && tmp <= 9)
            {
                vec.push_back(tmp);
            }
            else
            {
                vec.push_back(str[i] - '7');
            }
        }
        ans = solution(vec, n, k);

        printf("#%d %lld\n", i, ans);
    }
    return 0;
}