#include <vector>
#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;
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
    

    // int pSize = participant.size();
    // int cSize = completion.size();

    // for (int i = 0; i < pSize; i++)
    // {
    //     for (int j = 0; j < cSize; j++)
    //     {
    //         if (participant[i] == completion[j])
    //         {
    //             participant[i] = "";
    //             completion[j] = "";
    //             break;
    //         }
    //     }
    //     answer += participant[i];
    // }

    auto end = chrono::high_resolution_clock::now();

    cout << "Code Duration : " << (float)(end - start).count() / CLOCKS_PER_SEC << " sec" << endl;

    return answer;
}