#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iostream>

using namespace std;

float solution(vector<string> participant, vector<string> completion);

int main(int argc, char const *argv[])
{

    cout << solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}) << " sec" << endl;

    return 0;
}

float solution(vector<string> participant, vector<string> completion)
{
    string answer = "";

    auto start = chrono::high_resolution_clock::now();
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    auto end = chrono::high_resolution_clock::now();
    float Time = (float)(end - start).count() / CLOCKS_PER_SEC;

    return Time;
}