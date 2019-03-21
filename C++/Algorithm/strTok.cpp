#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**
 *  * stringstream 을 이용한  Tokenizer
 *  * 템플릿 함수를 이용하여 가용성 높임
 *  * but, delemeter 지정 불가
 *  * string에서 int형만 빼고 싶을 때, int형 자료 앞에 다른 형태가 있으면 끊어짐 (when use while loop)
 */
template <typename T>
vector<T> sstrtok(string str)
{
    vector<T> result;
    stringstream ss;
    ss.str(str);
    T type;
    while (ss >> type)  // TODO FIXME
    {
        result.push_back(type);
    }

    return result;
}

/**
 *  * string iterator를 이용한 tokenizer
 */
vector<string> strtok(string str, char delemeter = ' ')
{
    vector<string> result;

    auto itr = str.begin();
    int idx = 0;
    int cnt = 1;
    while (itr != str.end())
    {
        if (*itr == delemeter || *itr == str.back())
        {
            string tmpstr;
            int current = (*itr == str.back()) ? str.size() : (itr - str.begin());
            tmpstr.assign(str, idx, current - idx);
            result.push_back(tmpstr);
            cout << cnt << " : " << result.back() << endl;
            idx = current + 1;
            cnt++;
        }
        itr++;
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<string> ans;
    vector<float> ans2;
    // ans = strtok("abc bcd 178");
    string tmp;
    ans = sstrtok<string>("abc 123 ABC");
    ans2 = sstrtok<float>("abc 123 ABC");

    int size = ans.size();
    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << endl;
    }

    size = ans2.size();
    cout << "ans2 size : " << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << ans2[i] << endl;
    }
    return 0;
}