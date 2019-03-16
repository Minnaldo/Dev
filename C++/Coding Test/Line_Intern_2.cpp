#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    string str;
    cin >> str;

    vector<string> answer;
    queue<char> q;

    int size = str.size();
    int ato = 0, atonum = 0;

    for (int i = 0; i < size; i++)
    {
        int tmp = str[i] - 'A';
        if (tmp >= 0 && tmp <= 25) // 대문자 범위
        {
            ato++;
            int tmp2 = str[i + 1] - 'a';
            if (tmp2 >= 0 && tmp <= 25) // 소문자 범위
            {
                q.push(str[i] + str[i + 1]);
                i += 2;
            }
            else
            {
                string tmpstr = to_string(tmp + 'A');
                q.push(str[i]);
            }
        }
        else if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
        {
            // 숫자일 때
            atonum++;
            // 1이 나온 경우 --> 뒤에 0이 있는지 확인
            if (str[i] - '0' == 1)
            {
                if (str[i + 1] - '0' == 0)
                {
                    // 10, 문자뒤에 10을 붙여 출력
                    string ansStr = q.front() + to_string(10);
                    // cout << ansStr;
                    answer.push_back(ansStr);
                    i += 2;
                }
                else
                {
                    // 1, 문자만 출력
                    // cout << q.front();
                    char tmp = q.front();
                    string ansStr = &tmp;
                    answer.push_back(ansStr);
                }
            }
            else
            {
                // 문자 뒤 숫자를 붙여 출력
                string ansStr = q.front() + to_string(str[i] - '0');
                // cout << ansStr;
                answer.push_back(ansStr);
            }
            q.pop();
        }
    }

    if (ato == atonum)
    {
        int ansSize = answer.size();
        for (int i = 0; i < ansSize; i++)
        {
            cout << answer[i];
        }
        cout << endl;
    }
    else
    {
        cout << "error" << endl;
    }

    return 0;
}