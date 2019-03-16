#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string cryptogram)
{
    string answer = "";
    auto itr = cryptogram.begin();

    while (itr != cryptogram.end())
    {
        if (*itr == *(itr + 1))
        {
            cryptogram.erase(itr, itr + 2);
            itr = cryptogram.begin();
        }
        else
        {
            itr++;
        }
    }

    answer = cryptogram;

    return answer;
}

int main(int argc, char const *argv[])
{
    string str = "browoanoommnaon";
    string str2 = "zyelleyz";
    cout << solution(str) << endl;
    return 0;
}