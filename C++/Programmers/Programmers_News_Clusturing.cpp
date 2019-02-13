//News Clusturing

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2);
int jFunction(int hap, int gyo);

int main(int argc, char const *argv[])
{
    string str1 = "FRANCE";
    string str2 = "french";
    solution(str1, str2);
    return 0;
}
int jFunction(int hap, int gyo)
{

    if (gyo != 0)
    {
        return (hap / gyo) * 65536;
    }
}
int solution(string str1, string str2)
{
    int answer = 0;
    vector<string> mat1;
    vector<string> mat2;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for (int i = 0; i < str1.size(); i++)
    {
        mat1.push_back(str1.at(i));
    }

    for (int i = 0; i < str2.size(); i++)
    {
        mat2.push_back(str2[i]);
    }

    return answer;
}