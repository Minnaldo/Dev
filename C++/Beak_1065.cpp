#include <cmath>
#include <iostream>

using namespace std;

/** 한수 백준_1065 (https://www.acmicpc.net/problem/1065)
 *  * 많이 틀린 이유 ==> 문자열끼리 비교했다 -> Correct Answer : char -> int 후 비교해야 정확한 비교가 된다
 *  * 한자리수와 두자리수는 무조건 등차수열이 된다
 */

int cnt;

int solution(int n)
{
    if (n >= 100)
    {
        cnt = 99;
        for (int i = 100; i <= n; i++)
        {
            string str = to_string(i);
            int str_size = str.size();

            if (str_size == 3)
            {
                if ((str[0] - '\0' < str[1] - '\0' && str[1] - '\0' < str[2] - '\0') || (str[0] - '\0' > str[1] - '\0' && str[1] - '\0' > str[2] - '\0') || (str[0] - '\0' == str[1] - '\0' && str[1] - '\0' == str[2] - '\0'))
                    if (abs((str[1] - '\0') - (str[0] - '\0')) == abs((str[2] - '\0') - (str[1] - '\0')))
                    {
                        cnt++;
                    }
            }
        }
    }
    else if (n < 100)
    {
        cnt = n;
    }

    return cnt;
}

int main(int argc, char const *argv[])
{
    //  ex) 1000 : 144, 110 : 99
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << solution(n) << "\n";
    return 0;
}