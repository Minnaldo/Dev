#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

/**
 *  * 문자열이 10만개만 넘어가도 느려짐
 *
 */

using namespace std;

string find_pattern(string s)
{
    char begin = s[0];
    auto tmpitr = find(s.begin() + 1, s.end(), begin);

    auto itr = s.begin();
    string tmp;
    for (itr; itr != tmpitr; itr++)
    {
        // 패턴 완성
        tmp += (*itr);
    }
    return tmp;
}

int solution(string s)
{
    int answer = 2000001;
    string pattern = find_pattern(s);

    // 패턴 매칭
    int flag = 0, idx = 0;
    int ptsize = pattern.size(), size = s.size();
    while (idx < size)
    {
        auto tmp = s.find_first_not_of(pattern, idx);

        if (tmp != string::npos)
        {
            pattern += s[pattern.size()]; // 패턴에 문자열 추가
            ptsize = pattern.size();
            idx = ptsize;
            flag = 0;
            if (ptsize > size / 2)
            {
                answer = size;
                break;
            }
            answer = ptsize;
        }
        else
        {
            flag = 1;
            idx += ptsize;
            answer = min(answer, ptsize);
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    string str = "abababab";
    string str2 = "abcabcabd";
    string str3 = "";

    for (int i = 0; i < 100000; i++)
    {
        str3 += "a";
    }

    auto start = chrono::system_clock::now();
    cout << "answer : " << solution(str3) << endl;
    auto end = chrono::system_clock::now();
    cout << (double)(end - start).count() / CLOCKS_PER_SEC << endl;
    return 0;
}