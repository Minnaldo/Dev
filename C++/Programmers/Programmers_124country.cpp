#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n);

int main(int argc, char const *argv[])
{
    cout << solution(4) << endl;
    return 0;
}

string solution(int n)
{
    string answer = "";
    vector<string> strV;
    vector<int> vecNum;

    for (int i = 1; i <= n; i++)
    {
        if (i != n)
        {
            for (int q = vecNum.size(); q > 0; q--)
            {
                if (q != 1)
                {
                    if (q != vecNum.size())
                    {
                        switch (check)
                        {
                        case 0:
                            break;
                        case 1:
                            break;
                        }
                    }
                    else
                    {
                        switch (vecNum[q])
                        {
                        case 1:
                            vecNum[q] = 2;
                            check = 0;
                            break;
                        case 2:
                            vecNum[q] = 4;
                            check = 0;
                            break;
                        case 4:
                            vecNum[q] = 1;
                            check = 1;
                            break;
                        }
                    }
                }
                else
                {
                    if (vecNum.at(q) == 4)
                    {
                        vecNum.at(q) = 1;
                        vecNum.push_back(1);
                    }
                }
            }
        }
        else
        {
            for (int j = 0; j < vecNum.size(); j++)
            {
                answer += vecNum[j];
            }
        }
    }

    return answer;
}