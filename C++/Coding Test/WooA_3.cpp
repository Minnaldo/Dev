#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// ! ASCII to STring

using namespace std;

string solution(string word)
{
    string answer = "";
    int size = word.size();

    for (int i = 0; i < size; i++)
    {
        if (word[i] != ' ')
        {
            string tmpStr = "";
            if (word[i] - 'A' >= 0 && word[i] - 'A' <= 25)
            {
                tmpStr = 'Z' - (word[i] - 'A');
            }

            if (word[i] - 'a' >= 0 && word[i] - 'a' <= 25)
            {
                tmpStr = 'z' - (word[i] - 'a');
            }

            answer += tmpStr;
        }
        else
        {
            answer += " ";
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    string str;
    getline(cin,str);

    cout << solution(str) << endl;

    return 0;
}