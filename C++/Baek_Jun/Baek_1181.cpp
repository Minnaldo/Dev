#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

/** 단어 정렬 백준_1181 ( https://www.acmicpc.net/problem/1181 )
 *  * algorithm의 sort와 람다식을 이용하여 정렬
 *  * 1 조건 : 길이가 짧은 것부터
 *  * 2 조건 : 길이가 같으면 사전순
 *  * 중복 입력은 하나만 출력한다 --> 중복제거 : set 자료구조를 이용 / algorithm -> unique()이용
 *  * unique 이용시에는 정렬을 한 후에 사용해야 한다
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    // string *arr = new string[N + 1];
    vector<string> arr;

    set<string> s;
    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        s.insert(str);
    }

    auto itr = s.begin();
    for (itr; itr != s.end(); itr++)
    {
        arr.push_back(*itr);
    }

    // 조건에 맞춰 오름차순 정렬
    // () 안의 변수를 밖에서 받아와 안에서 비교후 참 거짓 리턴
    // NOTE I need to study for sort function in algorithm header
    sort(arr.begin(), arr.end(), [](string str1, string str2) {
        if (str1.size() == str2.size())
        {
            return str1.compare(str2) < 0 ? true : false;
        }
        return str1.size() < str2.size() ? true : false;
    });

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\n";
    }

    return 0;
}