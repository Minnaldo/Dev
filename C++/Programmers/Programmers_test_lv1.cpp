#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution2(string phone_number)
{
    string answer = "";

    int size = phone_number.size();
    for(int i =0; i<size-4;i++)
    {
        answer.append("*");
    }
    answer.append(phone_number.substr(size-4));

    return answer;
}

int solution(int n)
{
    int answer = 0;

    for (int i = 0; i <= n; i++)
    {
        if (n % i == 0)
            answer += i;
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    int n;
    string n2;
    cin >> n2;
    cout << solution2(n2) << endl;
    return 0;
}