#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/** 단어 정렬 백준_1181 ( https://www.acmicpc.net/problem/1181 )
 *  * algorithm의 sort와 람다식을 이용하여 정렬
 *  * 1 조건 : 길이가 짧은 것부터
 *  * 2 조건 : 길이가 같으면 사전순
 *  * 중복 입력은 하나만 출력한다
 *  ! 시간초과
 */

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    // string *arr = new string[N + 1];
    vector<string> arr(N + 1);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // 중복 제거
    for (int i = 0; i < arr.size(); i++)
    {
        if (count(arr.begin(), arr.end(), arr[i]) > 1)
        {
            arr.erase(find(arr.begin(), arr.end(), arr[i]));
        }
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

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}