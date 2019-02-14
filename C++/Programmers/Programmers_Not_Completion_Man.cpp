#include <vector>
#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;

/** https://programmers.co.kr/learn/courses/30/lessons/42576 (완주하지 못한 선수)
 *
 */

string solution(vector<string> participant, vector<string> completion);

int main(int argc, char const *argv[])
{
    cout << solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}) << endl;
    return 0;
}

//TODO: 효율성 문제 생김
string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";

    auto start = chrono::high_resolution_clock::now();

    auto citr = completion.begin();
    auto pitr = participant.begin();
    auto epitr = participant.end();

    //이름이 같으면 뺀다

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < completion.size(); i++)
    {
        if (participant[i] != completion[i])
            return participant[i];
    }
    return participant[participant.size() - 1];

    auto end = chrono::high_resolution_clock::now();

    cout << "Code Duration : " << (float)(end - start).count() / CLOCKS_PER_SEC << " sec" << endl;

}