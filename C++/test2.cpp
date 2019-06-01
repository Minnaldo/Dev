#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;

    // 문자열 길이로 오름차순 정렬
    sort(phone_book.begin(), phone_book.end(), [](string str1, string str2) -> bool {
        str1.size() < str2.size() ? true : false;
    });

    int size = phone_book.size();
    for (int i = 0; i < size; i++)
    {
        string tmpStr = phone_book[i];
        for (int j = i + 1; j < size; j++)
        {
            string tmp = phone_book[j].substr(0, tmpStr.size());

            if (tmpStr.compare(tmp) == 0)
            {
                return false;
            }
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<string> book = {"119", "97674223", "1195524421"};
    vector<string> book2 = {"123", "456", "789"};
    vector<string> book3 = {"12", "123", "1235", "567", "88"};

    bool ans = solution(book);

    if (ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}