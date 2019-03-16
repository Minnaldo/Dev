#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int number)
{
    int answer = 0;
    string str;

    for (int i = 1; i <= number; i++)
    {
        str = to_string(i);

        answer += count(str.begin(), str.end(), '3');
        answer += count(str.begin(), str.end(), '6');
        answer += count(str.begin(), str.end(), '9');
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    cout << solution(N) << endl;
    return 0;
}