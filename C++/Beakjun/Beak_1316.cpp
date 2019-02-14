#include <iostream>
#include <string>

/** 그룹 단어 체커 백준_1316 (https://www.acmicpc.net/problem/1316)
 *  TODO
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    ifstream fs("input.txt");

    int n, cnt = 0, ret = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int size = str.size();

        if (size > 1)
        {
            for (int j = 0; j < size; j++)
            {
                if (str[j] != str[j + 1] && str[j + 1] != EOF)
                {
                    for (int k = j + 1; k < size; k++)
                    {
                        if (str[j] == str[k])
                            cnt++;
                    }
                }

                if (cnt > 0)
                    break;
            }

            if (cnt == 0)
            {
                ret++;
            }
            cnt = 0;
        }
        else if (size == 1)
        {
            ret++;
        }
    }

    cout << ret << "\n";

    return 0;
}