#include <iostream>
#include <string>

using namespace std;

/** KMP는 왜 KMP일까 백준_2902 (https://www.acmicpc.net/problem/2902)
 *
 */

string solution(char *str)
{
    string tmp = "";
    tmp.push_back(str[0]);
    int idx = 1;
    while (str[idx] != '\0')
    {
        if (str[idx] == '-')
        {
            tmp.push_back(str[idx + 1]);
        }
        idx++;
    }

    return tmp;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    char str[100];
    cin.getline(str, sizeof(str));
    cout << solution(str) << "\n";
    return 0;
}