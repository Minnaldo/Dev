#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b)
{
    string answer = "";
    int tmp = b;
    if (a != 1)
    {
        for (int i = 2; i < a - 1; i++)
        {
            if (i != 2)
            {
                if (i % 2 == 1)
                {
                    tmp += 31;
                }
                else
                {
                    if (i == 8)
                    {
                        tmp += 31;
                        continue;
                    }
                    tmp += 30;
                }
            }
            else
            {
                tmp += 29;
            }
        }
    }

    switch (tmp % 7)
    {
    case 1:
        answer += "FRI";
        break;
    case 2:
        answer += "SAT";
        break;
    case 3:
        answer += "SUN";
        break;
    case 4:
        answer += "MON";
        break;
    case 5:
        answer += "TUE";
        break;
    case 6:
        answer += "WED";
        break;
    case 0:
        answer += "THU";
        break;
    }
    return answer;
}

int main()
{
    cout << solution(5, 24) << endl;
}